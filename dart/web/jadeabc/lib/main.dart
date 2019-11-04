import 'package:flutter/material.dart';
import 'dart:math';
import 'dart:html';
import 'package:audioplayers/audio_cache.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      theme: ThemeData(
        // This is the theme of your application.
        //
        // Try running your application with "flutter run". You'll see the
        // application has a blue toolbar. Then, without quitting the app, try
        // changing the primarySwatch below to Colors.green and then invoke
        // "hot reload" (press "r" in the console where you ran "flutter run",
        // or simply save your changes to "hot reload" in a Flutter IDE).
        // Notice that the counter didn't reset back to zero; the application
        // is not restarted.
        primarySwatch: Colors.blue,
      ),
      home: MyHomePage(title: "Jade's ABCs"),
    );
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePage({Key key, this.title}) : super(key: key);

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage>
  with SingleTickerProviderStateMixin {
  int _counter = 0;
  String _abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  final _random = new Random();
  int _max_width;
  int _max_height;
  int _top;
  int _left;
  Offset _old_values;
  int _stop_char=1;
  double _width = 200;
  double _height = 200;
  static AudioCache _player = new AudioCache();
  AudioElement _audio;
  Animation<Offset> _animation;
  AnimationController _animationController;

  /**
   * Generates a positive random integer uniformly distributed on the range
   * from [min], inclusive, to [max], exclusive.
   */
  int _next(int min, int max) => min + _random.nextInt(max - min);

  void _setup(double value) {
    setState((){
      _stop_char=value.toInt();
      // print("value has been changed to $_stop_char");
    });
  }
void _incrementCounter() {
    setState(() {
      // This call to setState tells the Flutter framework that something has
      // changed in this State, which causes it to rerun the build method below
      // so that the display can reflect the updated values. If we changed
      // _counter without calling setState(), then the build method would not be
      // called again, and so nothing would appear to happen.
      //  _player.play(_abc[_counter].toLowerCase()+".mp3");
      _audio=AudioElement("assets/assets/"+_abc[_counter].toLowerCase()+".mp3");
      _audio.muted=false;
      _audio.play();
      _counter = (_counter + 1) % (_stop_char+1);
      _old_values=Offset(_left.toDouble(),_top.toDouble());
      _top = _next(80,(_max_height - _height).floor());
      _left = _random.nextInt((_max_width - _width).floor());
      print("_counter=$_counter scha=$_stop_char max_height=$_max_height");
      _animationController.reset();
      _animation=Tween<Offset>(
        begin:_old_values,
        end:Offset(_left.toDouble(), _top.toDouble())
      ).animate(_animationController)..addListener(() {
        // #enddocregion addListener
        setState(() {
          //print("animation value is ${_animation.value}");
        });
      });
      _animationController.forward();
    });
  }

  @override
  initState() {
    super.initState();
    _top = 80;
    _left = 10;
    _old_values=Offset(_left.toDouble(),_top.toDouble());
    _animationController=AnimationController(
        vsync: this,
        duration: Duration(milliseconds: 500),
    );
    _animation=Tween<Offset>(
      begin:_old_values,
      end:Offset(_left.toDouble(), _top.toDouble())
    ).animate(_animationController);
  }

  @override
  Widget build(BuildContext context) {
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    _max_width = MediaQuery
        .of(context)
        .size
        .width
        .toInt();
    _max_height = MediaQuery
        .of(context)
        .size
        .height
        .toInt() - 80;
    return SafeArea(
        child: Scaffold(
          appBar: AppBar(
            // Here we take the value from the MyHomePage object that was created by
            // the App.build method, and use it to set our appbar title.
            title: Text(widget.title),
          ),
          body: Stack(
            // Center is a layout widget. It takes a single child and positions it
            // in the middle of the parent.
            children: <Widget>[
          Column(
          // Column is also a layout widget. It takes a list of children and
          // arranges them vertically. By default, it sizes itself to fit its
          // children horizontally, and tries to be as tall as its parent.
          //
          // Invoke "debug painting" (press "p" in the console, choose the
          // "Toggle Debug Paint" action from the Flutter Inspector in Android
          // Studio, or the "Toggle Debug Paint" command in Visual Studio Code)
          // to see the wireframe for each widget.
          //
          // Column has various properties to control how it sizes itself and
          // how it positions its children. Here we use mainAxisAlignment to
          // center the children vertically; the main axis here is the vertical
          // axis because Columns are vertical (the cross axis would be
          // horizontal).
          // mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.stretch,
            mainAxisSize: MainAxisSize.max,
            children: <Widget>[
              Slider(
                value:_stop_char.toDouble(),
                onChanged: _setup,
                max: 26,
                min: 1,
                divisions: 25,
              ),
              Text(
                'Stops at ${_abc[_stop_char]}',
                style: Theme
                    .of(context)
                    .textTheme
                    .display1,
                textAlign: TextAlign.center,
              ),
            ],
          ),
          new Positioned(
            left: _animation.value.dx,
            top: _animation.value.dy,
            child: GestureDetector(
              child: Container(
                width: _width.toDouble(),
                height: _height.toDouble(),
                decoration: new BoxDecoration(color: Colors.red),
                child: Text(
                  '${_abc[_counter]}',
//                  style: Theme
//                      .of(context)
//                      .textTheme
//                      .display1,
                  style: TextStyle(fontSize: 120),
                  textAlign: TextAlign.center,
                ),
              ),
              onTap: _incrementCounter,
              onLongPress: _incrementCounter,
              //onLongPressEnd: _incrementCounter,
            ),
          )],
          ),
          floatingActionButton: FloatingActionButton(
            onPressed: _incrementCounter,
            tooltip: 'Increment',
            child: Icon(Icons.add),
          ), // This trailing comma makes auto-formatting nicer for build methods.
        ));
  }
}
