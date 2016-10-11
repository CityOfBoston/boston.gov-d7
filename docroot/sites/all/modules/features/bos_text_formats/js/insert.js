/**
 * @file
 * JavaScript to activate "Insert" buttons on file and image fields.
 */

(function ($) {

    /**
     * Behavior to add "Insert" buttons.
     */
    Drupal.behaviors.insert = {};
    Drupal.behaviors.insert.attach = function(context) {
        if (typeof(insertTextarea) == 'undefined') {
            insertTextarea = $('#edit-body textarea.text-full').get(0) || false;
        }

        // Keep track of the last active textarea (if not using WYSIWYG).
        $('textarea:not([name$="[data][title]"]):not(.insert-processed)', context).addClass('insert-processed').focus(insertSetActive).blur(insertRemoveActive);

        // Add the click handler to the insert button.
        $('.insert-button:not(.insert-processed)', context).addClass('insert-processed').click(insert);

        function insertSetActive() {
            insertTextarea = this;
            this.insertHasFocus = true;
        }

        function insertRemoveActive() {
            if (insertTextarea == this) {
                var thisTextarea = this;
                setTimeout(function() {
                    thisTextarea.insertHasFocus = false;
                }, 1000);
            }
        }

        function insert() {
            var widgetType = $(this).attr('rel');
            var settings = Drupal.settings.insert.widgets[widgetType];
            var wrapper = $(this).parents(settings.wrapper).filter(':first').get(0);
            var style = $('.insert-style', wrapper).val();
            var content = $('input.insert-template[name$="[' + style + ']"]', wrapper).val();
            var filename = $('input.insert-filename', wrapper).val();
            var options = {
                widgetType: widgetType,
                filename: filename,
                style: style,
                fields: {}
            };

            // Check for alt tag if image.
            if (widgetType == 'image_image') {
                if (settings.fields['alt']) {
                    var altText = $(settings.fields['alt'], wrapper).val()
                    if(altText.length < 1) {
                        alert('Alt text is missing.');
                        return false;
                    }
                }
            }

            // Update replacements.
            for (var fieldName in settings.fields) {
                var fieldValue = $(settings.fields[fieldName], wrapper).val();
                if (fieldValue) {
                    fieldValue = fieldValue
                        .replace(/&/g, '&amp;')
                        .replace(/"/g, '&quot;')
                        .replace(/'/g, '&#39;')
                        .replace(/</g, '&lt;')
                        .replace(/>/g, '&gt;');
                }
                options['fields'][fieldName] = fieldValue;
                if (fieldValue) {
                    var fieldRegExp = new RegExp('__' + fieldName + '(_or_filename)?__', 'g');
                    content = content.replace(fieldRegExp, fieldValue);
                }
                else {
                    var fieldRegExp = new RegExp('__' + fieldName + '_or_filename__', 'g');
                    var frame = $('#cke_' + Drupal.wysiwyg.activeId + ' iframe')[0];
                    var frameWindow = frame && frame.contentWindow;
                    var frameDocument = frameWindow && frameWindow.document;

                    if (frameDocument) {
                        var selected = '';
                        if (frameDocument.getSelection) {
                            // Most browsers
                            selected = String(frameDocument.getSelection());
                        }
                        else if (frameDocument.selection) {
                            // Internet Explorer 8 and below
                            selected = frameDocument.selection.createRange().text;
                        }
                        else if (frameWindow.getSelection) {
                            // Safari 3
                            selected = String(frameWindow.getSelection());
                        }

                        if (selected.length > 0) {
                            filename = selected;
                        }
                    }
                    content = content.replace(fieldRegExp, filename);
                }
            }

            // File name replacement.
            var fieldRegExp = new RegExp('__filename__', 'g');
            content = content.replace(fieldRegExp, filename);

            // Check for a maximum dimension and scale down the width if necessary.
            // This is intended for use with Image Resize Filter.
            var widthMatches = content.match(/width[ ]*=[ ]*"(\d*)"/i);
            var heightMatches = content.match(/height[ ]*=[ ]*"(\d*)"/i);
            if (settings.maxWidth && widthMatches && parseInt(widthMatches[1]) > settings.maxWidth) {
                var insertRatio = settings.maxWidth / widthMatches[1];
                var width = settings.maxWidth;
                content = content.replace(/width[ ]*=[ ]*"?(\d*)"?/i, 'width="' + width + '"');

                if (heightMatches) {
                    var height = Math.round(heightMatches[1] * insertRatio);
                    content = content.replace(/height[ ]*=[ ]*"?(\d*)"?/i, 'height="' + height + '"');
                }
            }

            // Allow other modules to perform replacements.
            options['content'] = content;
            $.event.trigger('insertIntoActiveEditor', [options]);
            content = options['content'];

            // Cleanup unused replacements.
            content = content.replace(/"__([a-z0-9_]+)__"/g, '""');

            // Cleanup empty attributes (other than alt).
            content = content.replace(/([a-z]+)[ ]*=[ ]*""/g, function(match, tagName) {
                return (tagName === 'alt') ? match : '';
            });

            // Insert the text.
            Drupal.insert.insertIntoActiveEditor(content);
        }
    };

// General Insert API functions.
    Drupal.insert = {
        /**
         * Insert content into the current (or last active) editor on the page. This
         * should work with most WYSIWYGs as well as plain textareas.
         *
         * @param content
         */
        insertIntoActiveEditor: function(content) {
            var editorElement;

            // Always work in normal text areas that currently have focus.
            if (insertTextarea && insertTextarea.insertHasFocus) {
                editorElement = insertTextarea;
                Drupal.insert.insertAtCursor(insertTextarea, content);
            }
            // Direct tinyMCE support.
            else if (typeof(tinyMCE) != 'undefined' && tinyMCE.activeEditor) {
                editorElement = document.getElementById(tinyMCE.activeEditor.editorId);
                Drupal.insert.activateTabPane(editorElement);
                tinyMCE.activeEditor.execCommand('mceInsertContent', false, content);
            }
            // WYSIWYG support, should work in all editors if available.
            else if (Drupal.wysiwyg && Drupal.wysiwyg.activeId) {
                editorElement = document.getElementById(Drupal.wysiwyg.activeId);
                Drupal.insert.activateTabPane(editorElement);
                Drupal.wysiwyg.instances[Drupal.wysiwyg.activeId].insert(content)
            }
            // FCKeditor module support.
            else if (typeof(FCKeditorAPI) != 'undefined' && typeof(fckActiveId) != 'undefined') {
                editorElement = document.getElementById(fckActiveId);
                Drupal.insert.activateTabPane(editorElement);
                FCKeditorAPI.Instances[fckActiveId].InsertHtml(content);
            }
            // Direct FCKeditor support (only body field supported).
            else if (typeof(FCKeditorAPI) != 'undefined') {
                // Try inserting into the body.
                if (FCKeditorAPI.Instances[insertTextarea.id]) {
                    editorElement = insertTextarea;
                    Drupal.insert.activateTabPane(editorElement);
                    FCKeditorAPI.Instances[insertTextarea.id].InsertHtml(content);
                }
                // Try inserting into the first instance we find (may occur with very
                // old versions of FCKeditor).
                else {
                    for (var n in FCKeditorAPI.Instances) {
                        editorElement = document.getElementById(n);
                        Drupal.insert.activateTabPane(editorElement);
                        FCKeditorAPI.Instances[n].InsertHtml(content);
                        break;
                    }
                }
            }
            // CKeditor module support.
            else if (typeof(CKEDITOR) != 'undefined' && typeof(Drupal.ckeditorActiveId) != 'undefined') {
                editorElement = document.getElementById(Drupal.ckeditorActiveId);
                Drupal.insert.activateTabPane(editorElement);
                CKEDITOR.instances[Drupal.ckeditorActiveId].insertHtml(content);
            }
            // Direct CKeditor support (only body field supported).
            else if (typeof(CKEDITOR) != 'undefined' && CKEDITOR.instances[insertTextarea.id]) {
                editorElement = insertTextarea;
                Drupal.insert.activateTabPane(editorElement);
                CKEDITOR.instances[insertTextarea.id].insertHtml(content);
            }
            else if (insertTextarea) {
                editorElement = insertTextarea;
                Drupal.insert.activateTabPane(editorElement);
                Drupal.insert.insertAtCursor(insertTextarea, content);
            }

            if (editorElement) {
                Drupal.insert.contentWarning(editorElement, content);
            }

            return false;
        },

        /**
         * Check for vertical tabs and activate the pane containing the editor.
         *
         * @param editor
         *   The DOM object of the editor that will be checked.
         */
        activateTabPane: function(editor) {
            var $pane = $(editor).parents('.vertical-tabs-pane:first');
            var $panes = $pane.parent('.vertical-tabs-panes');
            var $tabs = $panes.parents('.vertical-tabs:first').find('ul.vertical-tabs-list:first li a');
            if ($pane.size() && $pane.is(':hidden') && $panes.size() && $tabs.size()) {
                var index = $panes.children().index($pane);
                $tabs.eq(index).click();
            }
        },

        /**
         * Warn users when attempting to insert an image into an unsupported field.
         *
         * This function is only a 90% use-case, as it doesn't support when the filter
         * tip are hidden, themed, or when only one format is available. However it
         * should fail silently in these situations.
         */
        contentWarning: function(editorElement, content) {
            if (!content.match(/<img /)) return;

            var $wrapper = $(editorElement).parents('div.text-format-wrapper:first');
            if (!$wrapper.length) return;

            $wrapper.find('.filter-guidelines-item:visible li').each(function(index, element) {
                var expression = new RegExp(Drupal.t('Allowed HTML tags'));
                if (expression.exec(element.textContent) && !element.textContent.match(/<img>/)) {
                    alert(Drupal.t("The selected text format will not allow it to display images. The text format will need to be changed for this image to display properly when saved."));
                }
            });
        },

        /**
         * Insert content into a textarea at the current cursor position.
         *
         * @param editor
         *   The DOM object of the textarea that will receive the text.
         * @param content
         *   The string to be inserted.
         */
        insertAtCursor: function(editor, content) {
            // Record the current scroll position.
            var scroll = editor.scrollTop;

            // IE support.
            if (document.selection) {
                editor.focus();
                sel = document.selection.createRange();
                sel.text = content;
            }

            // Mozilla/Firefox/Netscape 7+ support.
            else if (editor.selectionStart || editor.selectionStart == '0') {
                var startPos = editor.selectionStart;
                var endPos = editor.selectionEnd;
                editor.value = editor.value.substring(0, startPos) + content + editor.value.substring(endPos, editor.value.length);
            }

            // Fallback, just add to the end of the content.
            else {
                editor.value += content;
            }

            // Ensure the textarea does not unexpectedly scroll.
            editor.scrollTop = scroll;
        }
    };

})(jQuery);
