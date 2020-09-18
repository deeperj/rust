@Grab('org.groovyfx:groovyfx:8.0.0')
//import javafx.scene.paint.Stop

import static groovyx.javafx.GroovyFX.start

start {
    stage(title: 'GroovyFX', show: true) {
        scene {
            rectangle(
                x: 10,
                y: 10,
                width: 150,
                height: 150,
                fill:hsb(128, 0.5, 0.5, 0.5)
            )
        }
    }
}

