// --------------------------------------------------------------------------------------------------------------------
// <copyright file="RibbonView.xaml.cs" company="WildGums">
//   Copyright (c) 2008 - 2014 WildGums. All rights reserved.
// </copyright>
// --------------------------------------------------------------------------------------------------------------------
    using Orchestra;
    // using System.Windows.Media;
    // using System.Windows.Media.Imaging;
    using Catel.Windows.Controls;
    // using Catel.IoC;
    // using Catel.Logging;
    // using Fluent;
    // using Services;
    // using FluentButton = Fluent.Button;
    // using System.Windows;
    // using System.Windows.Controls;

namespace wpftest
{
    public partial class RibbonView //: UserControl
    {
        #region Constructors
        public RibbonView()
        {
            InitializeComponent();

            //ribbon.AddAboutButton();
        }
        #endregion

        #region Methods
        protected override void OnViewModelChanged()
        {
            base.OnViewModelChanged();

// #pragma warning disable WPF0041
//             backstageTabControl.DataContext = ViewModel;
// #pragma warning restore WPF0041
        }
        #endregion
    }
}