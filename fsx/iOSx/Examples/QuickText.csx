//
// Quick Text Example
//
// Enables you to create a list of messages.
//
// 1. Add the ability to delete messages
// 2. Add the most recent message at the top
//

using System;
using System.Collections.ObjectModel;
using System.Linq;

using Foundation;
using UIKit;
using Xamarin.Forms;

//
// Setup a "database" of quick messages stored in a text file.
//
var messages = new ObservableCollection<string> ();

void ReadMessages () {
    try {
        var lines = System.IO.File.ReadLines ("QuickTextMessages.txt");
        messages.Clear();
        foreach (var line in lines) {
            messages.Add(line);
        }
    }
    catch {
        messages.Add("Hello!");
    }   
}
void SaveMessages () {
    try {
        System.IO.File.WriteAllLines ("QuickTextMessages.txt", messages);
    }
    catch { }   
}
ReadMessages();

//
// Construct the UI
//
var list = new ListView();

list.ItemsSource = messages;

var listPage = new ContentPage {
    Content = list,
    Title = "Quick Text",
};

var addItem = new ToolbarItem {
    Text = "Add",
};
listPage.ToolbarItems.Add(addItem);

//
// Add interaction
//
addItem.Clicked += (s,e) => {
    
    // Create an add message UI
    var alert = new UIAlertView("Add Message", "", null, "Cancel", "Add");
    alert.AlertViewStyle = UIAlertViewStyle.PlainTextInput;
    
    // Handle the user input
    alert.Clicked += (ss,ee) => {
        if (ee.ButtonIndex != alert.CancelButtonIndex) {
            messages.Add(alert.GetTextField(0).Text ?? "");
            SaveMessages();
        }
    };
    
    alert.Show();
};

list.ItemSelected += (s, e) => {

    if (e.SelectedItem == null) return;
    
    // Get the selected message
    var message = (string)e.SelectedItem;
    
    // Deselect the list cell
    list.SelectedItem = null;

    // Say hi
    Console.WriteLine($"Selected \"{message}\"");
};

//
// Display
//
var Main = new NavigationPage(listPage);










