@Grapes([
  @Grab("org.gebish:geb-core:0.9.0"),
  @Grab("org.gebish:geb-spock:0.9.0"),
  //@Grab("org.seleniumhq.selenium:selenium-firefox-driver:2.33.0"),
  @Grab("org.seleniumhq.selenium:selenium-chrome-driver:2.46.0"),
  @Grab("org.seleniumhq.selenium:selenium-support:2.26.0"),
  @Grab( group='org.spockframework', 
    module='spock-core', 
    version='0.3'
  ),
  @Grab(group='org.gebish', module='geb-implicit-assertions', version='0.9.0')
])
import geb.Browser
import geb.spock.GebReportingSpec
import org.openqa.selenium.chrome.*
import spock.lang.Specification
import geb.navigator.NonEmptyNavigator
import geb.navigator.factory.*
import geb.Module
import geb.Page
System.setProperty("webdriver.chrome.driver", "C:\\programs\\chromedriver.exe");

ChromeOptions options = new ChromeOptions();
options.setBinary("C:\\programs\\chromium\\chrome.exe");

def browser = new Browser(driver: new ChromeDriver(options))    

//browser.go "http://www.google.com/"

//assert browser.title == "Google"

//browser.$("input", name: "q").value("query") 

browser.drive {
    to GebHomePage 

    manualsMenu.open()

    manualsMenu.links[0].click()

    at TheBookOfGebPage
}

class ManualsMenuModule extends Module {
    static content = {
        toggle { $("div.menu a.manuals") }
        linksContainer { $("#manuals-menu") }
        links { linksContainer.find("a") }
    }

    void open() {
        toggle.click()
        waitFor { !linksContainer.hasClass("animating") }
    }
}

class GebHomePage extends Page {
    static url = "http://gebish.org"

    static at = { title == "Geb - Very Groovy Browser Automation" }

    static content = {
        manualsMenu { module(ManualsMenuModule) }
    }
}

class TheBookOfGebPage extends Page {
    static at = { title.startsWith("The Book Of Geb") }
}