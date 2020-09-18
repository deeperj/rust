@Grab('org.groovyfx:groovyfx:8.0.0')
import static groovyx.javafx.GroovyFX.start

start {
    stage(title: 'GroovyFX', show: true) {
        scene {
            rectangle(
                x: 10,
                y: 10,
                width: 35,
                height: 20,
                fill: "#ff0000",
                strokeWidth: 5
            )
        }
    }
}

