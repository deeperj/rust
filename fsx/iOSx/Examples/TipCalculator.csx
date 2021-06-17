//
// Tip Calculator Example
//
// Calculates a tip and total given a bill amount
//


using System;

using Xamarin.Forms;

var title = new Label() {
    Text = "Tip Calculator",
    FontSize = 32,
    HorizontalOptions = LayoutOptions.Center,
    Margin = new Thickness(0, 32, 0, 0),
};

var billEntry = new Entry() {
    FontSize = 32,
    Placeholder = (0.0).ToString("C"),
    HeightRequest = 44,
    HorizontalTextAlignment = TextAlignment.Center,
    Margin = new Thickness(50, 0, 50, 0),
};

var tip = new Label() {
    Text = "Tip",
    FontSize = 28,
    HorizontalOptions = LayoutOptions.Center,
};

var total = new Label() {
    Text = "Total",
    FontSize = 28,
    HorizontalOptions = LayoutOptions.Center,
};


void UpdateOutput() {
    var valtext = billEntry.Text;
    double val;
    if (!double.TryParse (valtext, out val)) {
        val = 0;
    }
    var tipval = val * 0.2;
    tipval = Math.Round (tipval, 2);
    tip.Text = "Tip " + tipval.ToString ("C");
    var tt = val + tipval;
    total.Text = "Total " + tt.ToString ("C");
}

billEntry.TextChanged += (s, e) => {
    UpdateOutput();
};

UpdateOutput();

var pageStack = new StackLayout ();
var outs = new StackLayout() {
    Margin = new Thickness(50, 0, 50, 0),
};
outs.Children.Add(tip);
outs.Children.Add(total);
outs.BackgroundColor = Color.FromRgb(150,200,190).WithLuminosity(0.8);
pageStack.Children.Add(title);
pageStack.Children.Add(billEntry);
pageStack.Children.Add(outs);
pageStack.BackgroundColor = Color.FromRgb(150,200,190);

var Main = new ContentPage() {
    Content = pageStack,
};



