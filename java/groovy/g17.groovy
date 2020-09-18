import groovy.swing.SwingBuilder 
import javax.swing.* 
import java.awt.*
 
// Create a builder 
def myapp = new SwingBuilder() 

// Compose the builder 
def myframe = myapp.frame(title : 'Tutorials Point', location : [200, 200], 
   size : [400, 300], defaultCloseOperation : WindowConstants.EXIT_ON_CLOSE) { 
      panel(layout: new GridLayout(3, 2, 5, 5)) { 
         label(text : 'Student Name:', horizontalAlignment : JLabel.RIGHT) 
         textField(text : '', columns : 10) 
			
         label(text : 'Subject Name:', horizontalAlignment : JLabel.RIGHT) 
         textField(text : '', columns : 10)
			
         label(text : 'School Name:', horizontalAlignment : JLabel.RIGHT) 
         textField(text : '', columns : 10) 
      } 
   } 
	
// The following  statement is used for displaying the form 
myframe.setVisible(true)