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
                fill:"linear (0%,0%) to (0%,100%) stops (0%,gray) (100%,black)" 
                // linearGradient(
                    // startX: 0.0,
                    // startY: 0.0,
                    // endX: 1.0,
                    // endY: 1.0,
                    // stops:[BLACK,WHITE,WHITE]
                //)
            )
        }
    }
}

