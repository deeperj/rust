//
// Plotting Example
//
// Demonstrates the use of OxyPlot to plot functions.
//

using System;
using System.Linq;

using OxyPlot;
using OxyPlot.Series;
using OxyPlot.Xamarin.iOS;

//
// Define some fun functions to plot
//
double SinWave(double x) => Math.Sin(x);
double SquareWave(double x) => Math.Sign(Math.Sin(x));

//
// Create a plot model that holds many series
//
var plot = new PlotModel();
plot.Title = "Hello Plotting";

//
// A little function to make adding plots easier
//
void AddFunction(Func<double, double> f, string name) {
    plot.Series.Add(new FunctionSeries(f,-10,10,100,name));
    plot.Series.Last().Background=OxyColor.FromRgb(255,250,230);
}

//
// Add functions to the plot
//
AddFunction(SinWave, "sin");
AddFunction(SquareWave, "square");

//
// Display the plot
//
var Main = new PlotView();
Main.Model = plot;

