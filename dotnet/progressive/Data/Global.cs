using Newtonsoft.Json;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System;
using progressive.Models;
using Microsoft.AspNetCore.Mvc.Rendering;

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

    public static IEnumerable<SelectListItem> GetEnumLookupKey<T>()
    {
        var mydic = new Dictionary<int, string>();
        foreach( var foo in Enum.GetValues(typeof(T)) )
        {
            mydic.Add((int)foo, foo.ToString());
        }
        return mydic.Select( (kv,k)=>new SelectListItem
        {
            Value = k.ToString(),
            Text = kv.Value
        }).ToList();
    }

    public static Dictionary<int, string> GetEnumDictionary_NOT_USED<T>() where T : struct
    {
        if (!typeof(T).IsEnum)
            throw new ArgumentException("T is not an Enum type");

        var mydic = new Dictionary<int, string>();
        // return Enum.GetValues(typeof(T))
        //     .Cast<object>()
        //     .ToDictionary(k => (int)k, v => ((Enum)v).GetDescription());
        foreach( var foo in Enum.GetValues(typeof(T)) )
        {
            mydic.Add((int)foo, foo.ToString());
        }
        return mydic;
    }

  }
}

