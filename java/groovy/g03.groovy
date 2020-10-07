import java.io.File 
class Example { 
   static void main(String[] args) { 
      new File('.','example2.txt').withWriter('utf-8') { 
         writer -> writer.writeLine 'Hello World' 
      }  
   } 
}