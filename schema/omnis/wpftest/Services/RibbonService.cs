﻿namespace wpftest.Services
{
    using System.Windows;
    using Orchestra.Services;
    using wpftest;

    public class RibbonService : IRibbonService
    {
        public FrameworkElement GetRibbon()
        {
            return new RibbonView();
        }

        public FrameworkElement GetMainView()
        {
            return new MainView();
        }

        public FrameworkElement GetStatusBar()
        {
            return new StatusBarView();
        }
    }
}