
module ui2
  open System;

  let openFD() : string = 
    let dlg = new Microsoft.Win32.OpenFileDialog()
    // dlg.FileName = "Document" Default file name
    // dlg.DefaultExt = ".txt" Default file extension
    //dlg.Filter = "Text documents (.txt)|*.txt"  Filter files by extension

    // Show open file dialog box
    let result = dlg.ShowDialog().Value

    // Process open file dialog box results
    if result = true then
      dlg.FileName
    else
      ""
    