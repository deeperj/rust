//
// Map Example
//
// Displays a point on a map
//
// Experiments:
// 1. Change the coordinate to your home
// 2. Add more pins
// 3. Change the map type to a satellite view
//

using System;

using UIKit;
using CoreGraphics;
using CoreLocation;
using MapKit;

// Create a view that displays the map
var mapView = new MKMapView (new CGRect(0,0,320,320));
    
// Note a 2D coordinate to display
var coord = new CLLocationCoordinate2D(
    47.6062, -122.3321);
    
// Place a pin at the coordinate
var pin = new MKPointAnnotation() {
    Coordinate = coord
};
mapView.AddAnnotations(pin);
        
// Display
var v = new UIView();
var Main = mapView;

