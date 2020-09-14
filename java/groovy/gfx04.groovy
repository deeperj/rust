@Grab('org.groovyfx:groovyfx:8.0.0')
import static groovyx.javafx.GroovyFX.start

start {
    stage(title: 'GroovyFX', show: true) {
        scene {
            polygon(points: [
                90,80,
                190,80,
                240,130,
                240,220,
                190,270,
                40,220,
                40,130
            ]
            )
        }
    }
}

