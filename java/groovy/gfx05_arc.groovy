@Grab('org.groovyfx:groovyfx:8.0.0')
import static groovyx.javafx.GroovyFX.start

start {
    stage(title: 'GroovyFX', show: true) {
        scene {
            arc(
                centerX: 125,
                centerY: 125,
                radiusX: 50,
                radiusY: 50,
                startAngle: 45,
                length: 270,
                type: "ROUND",
                fill: null,
                stroke: BLACK,
                strokeWidth: 5
            )
        }
    }
}

