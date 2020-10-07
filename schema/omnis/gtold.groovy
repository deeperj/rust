/*@Grapes([
    @Grab("org.gebish:geb-core:3.4"),
    @Grab("org.seleniumhq.selenium:selenium-firefox-driver:3.141.59"),
    @Grab("org.seleniumhq.selenium:selenium-support:3.141.59")
])
@Grapes([
    @Grab("org.gebish:geb-core:1.0"),
    @Grab("org.seleniumhq.selenium:selenium-firefox-driver:2.52.0"),
    @Grab("org.seleniumhq.selenium:selenium-support:2.52.0")
])*/
@Grapes([
        @Grab("org.gebish:geb-core:3.2"),
        //@Grab("org.seleniumhq.selenium:selenium-firefox-driver:3.141.59"),
        // @Grab("org.openqa.selenium.htmlunit.HtmlUnitDriver"),
        //@Grab("org.openqa.selenium.chrome.ChromeDriver:84.0.4147.125"),
        @Grab("org.seleniumhq.selenium:selenium-chrome-driver:2.33.0"),
        @Grab("org.seleniumhq.selenium:selenium-support:3.141.59"),
        @GrabExclude("org.codehaus.groovy:groovy-all")
])
import geb.Module
import geb.Page
import geb.Browser

Browser.drive {
    go "http://gebish.org"

    assert title == "Geb - Very Groovy Browser Automation" 

    $("div.menu a.manuals").click() 
    waitFor { !$("#manuals-menu").hasClass("animating") } 

    $("#manuals-menu a")[0].click() 

    assert title.startsWith("The Book Of Geb") 
}