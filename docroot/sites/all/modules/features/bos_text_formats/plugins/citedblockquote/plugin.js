
/**
 * @file
 * Plugin file for McLean Cited Blockquote.
 */

CKEDITOR.plugins.add('citedblockquote', {
  init: function( editor ) {
    editor.addCommand( 'citedblockquoteDialog', new CKEDITOR.dialogCommand('citedblockquoteDialog'));
    editor.ui.addButton( 'CitedBlockquote', {
      label: 'Insert Blockquote',
      command: 'citedblockquoteDialog',
      icon: this.path + 'icons/format_quote.png'
    });
    CKEDITOR.dialog.add( 'citedblockquoteDialog', this.path + 'dialogs/citedblockquote.js' );
    editor.on( 'doubleclick', function( evt )
    {
      var element = evt.data.element;

      if (element.is('blockquote'))
        evt.data.dialog = 'citedblockquoteDialog';
    });
  }
});
