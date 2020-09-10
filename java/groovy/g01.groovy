
import java.io.File 
class Example { 
   static void main(String[] args) { 
      new File("example.txt").eachLine {  
         line -> println "line : $line"; 
      } 
   } 
}