@Grapes([
  @Grab("org.gebish:geb-core:0.9.0"),
  @Grab("org.gebish:geb-spock:0.9.0"),
  @Grab("org.seleniumhq.selenium:selenium-firefox-driver:2.33.0"),
  //@Grab("org.seleniumhq.selenium:selenium-chrome-driver:2.46.0"),
  @Grab("org.seleniumhq.selenium:selenium-support:2.26.0"),
  @Grab( group='org.spockframework', 
    module='spock-core', 
    version='0.3'
  ),
  @Grab(group='org.gebish', module='geb-implicit-assertions', version='0.9.0')
])
import geb.Browser
import geb.spock.GebReportingSpec
//import org.openqa.selenium.chrome.*
import spock.lang.Specification
import geb.navigator.NonEmptyNavigator
import geb.navigator.factory.*
// System.setProperty("webdriver.chrome.driver", "C:\\programs\\chromedriver.exe");

// ChromeOptions options = new ChromeOptions();
// options.setBinary("C:\\programs\\chromium\\chrome.exe");

// def browser = new Browser(driver: new ChromeDriver(options))    

// browser.go "http://www.google.com/"

// assert browser.title == "Google"

// browser.$("input", name: "q").value("query") 

Browser.drive {
    go "http://gebish.org"

    assert title == "Geb - Very Groovy Browser Automation" 

    $("div.menu a.manuals").click() 
    waitFor { !$("#manuals-menu").hasClass("animating") } 

    $("#manuals-menu a")[0].click() 

    assert title.startsWith("The Book Of Geb") 
}