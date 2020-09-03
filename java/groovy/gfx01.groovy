@Grab('org.groovyfx:groovyfx:8.0.0')
import static groovyx.javafx.GroovyFX.start

cool="llcoolJ";
start {
    stage(title: 'GroovyFX Hello World', visible: true) {
        scene(fill: WHITE, width: 250, height: 250) {
            text(x:10,y:100,font: '80pt sanserif',text:cool){
            }
        }
    }
}