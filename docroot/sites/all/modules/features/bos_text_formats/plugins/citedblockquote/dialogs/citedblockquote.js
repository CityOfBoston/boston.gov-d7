
/**
 * @file
 * Cited Blockquote dialog.
 */
CKEDITOR.dialog.add('citedblockquoteDialog', function (editor) {
  return {
    title: 'Blockquote Properties',
    minWidth: 400,
    minHeight: 200,

    contents: [
      {
        id: 'tab-basic',
        label: 'Basic Settings',
        elements: [
          // Text area element for quote itself.
          {
            type: 'textarea',
            id: 'quote',
            label: 'Quote',
            // Make it required
            validate: CKEDITOR.dialog.validate.notEmpty("Quote field cannot be empty"),

            // Specify a set-up callback which will populate the textarea when
            // the dialog is opened.
            setup: function(element) {
              //console.log(element);
              // Remove the cite tag and replace br tags with line breaks.
              var content = element.getHtml().replace(/(<footer>.*<\/footer>)/gi, '')
                .replace(/<br>/gi, '\n')
                .replace(/<q>/gi, '')
                .replace(/<\/q>/gi, '');
              this.setValue(content);
            },

            // Specify a commit callback which should populate the chosen
            // element when the dialog gets OK.
            commit: function(element) {
              // Turn line breaks back to <br> tags and set the element.
              var content = this.getValue().replace(/(\r\n|\n|\r)/gm, '<br>');
              element.setHtml('<q>' + content + '</q>');
            }
          },

          // Text field for the citation.
          {
            type: 'text',
            id: 'citation',
            label: 'Citation',
            // Specify a set-up callback which will populate the textarea when
            // the dialog is opened.
            setup: function(element) {
              // Get the citation from the element.
              var citations = element.getElementsByTag('footer');
              if (citations.count() > 0) {
                // Set the field to the citation html.
                var citation = citations.getItem(0);
                this.setValue(citation.getHtml());
              }
            },

            // Specify commit callback to set citation.
            commit: function(element) {
              if (this.getValue() !== '') {
                var citations = element.getElementsByTag('footer');
                if (citations.length > 0) {
                  var citation = citations[0];
                  citation.setText(this.getValue());
                }
                else {
                  var citation = editor.document.createElement('footer');
                  citation.setText(this.getValue());
                  element.append(citation);
                }
              }
            }
          }
        ]
      }
    ],

    // Specify on Show event to setup the element before it goes to the
    // dialog.
    onShow: function() {
      var selection = editor.getSelection(),
        element = selection.getStartElement(),
        text = selection.getSelectedText();
      if (element)
        element = element.getAscendant('blockquote', true);

      if (!element || element.getName() != 'blockquote' || element.data('cke-realelement')) {
        var element = new CKEDITOR.dom.element('blockquote');

        if (text.trim() != '') {
          element.setHtml('<q>' + text + '</q>');
        }
        this.insertMode = true;
      }
      else
        this.insertMode = false;

      this.element = element;
      this.setupContent(this.element);

    },

    // After OK, set the element.
    onOk: function() {
      var dialog = this,
        quote = this.element;

      this.commitContent(quote);

      if (this.insertMode )
        editor.insertElement(quote);
    }
  };
});
