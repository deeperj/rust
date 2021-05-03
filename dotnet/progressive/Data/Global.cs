using Newtonsoft.Json;

namespace progressive.Data{
  public class Global{
    public static string UnimailSuffix = "@unimail.hud.ac.uk";
    public static string StudEmailSuffix = "@unimail.hud.ac.uk";
    public static void AppStartup(){
      JsonConvert.DefaultSettings = () => new JsonSerializerSettings {
        Formatting = Newtonsoft.Json.Formatting.Indented,
        ReferenceLoopHandling = Newtonsoft.Json.ReferenceLoopHandling.Ignore
      };
    }
  }
}

