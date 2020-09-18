@Grab('org.groovyfx:groovyfx:8.0.0')
import static groovyx.javafx.GroovyFX.start

start {
    stage(title: 'GroovyFX', show: true) {
        scene {
            ellipse(
                centerX: 50,
                centerY: 50,
                radiusX: 35,
                radiusY: 20,
                fill: BLACK,
                strokeWidth: 5
            )
        }
    }
}

