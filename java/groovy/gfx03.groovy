@Grab('org.groovyfx:groovyfx:8.0.0')
import static groovyx.javafx.GroovyFX.start

start {
    stage(title: 'GroovyFX', show: true) {
        scene {
            line(startX: 10, startY: 10, 
            endX: 150, endY: 150
            ,strokeWidth: 15
            ,stroke: TOMATO
            )
        }
    }
}

