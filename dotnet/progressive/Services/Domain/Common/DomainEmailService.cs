using FluentEmail.Core;
using FluentEmail.Smtp;
using System;
using System.Net.Mail;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Microsoft.AspNetCore.Http;
using progressive.Data;
using progressive.Models;
using EmailService;
using Newtonsoft.Json;

namespace progressive.Services.Domain.Common
{
    public class DomainEmailService : IDomainEmailService
    {
      private IEmailSender _sender;
      public string Password { 
        set{
            _sender.Password=value;
        } 
      }
      public DomainEmailService(IEmailSender sender)
      {
        _sender = sender;
      }

      public async Task<EmailStatus> LocalSendStatus(IEnumerable<ModuleTask> tasks,Student stud)
      {
        var sender = new SmtpSender(() => new SmtpClient("localhost")
        {
            EnableSsl = false,
            DeliveryMethod = SmtpDeliveryMethod.Network,
            Port = 25
        });
        var msg = PrepareStatus(tasks,stud);
        Email.DefaultSender = sender;

        var email = await Email
            .From("progressive@dashboard.com")
            .To(msg.SendTo)
            .Subject(msg.Subject)
            .Body(msg.Content)
            .SendAsync();
        return EmailStatus.Sent;
      }

      public async Task<EmailStatus>  StudentStatusEmail (IEnumerable<ModuleTask> tasks,Student stud)
      {
        var msg=PrepareStatus(tasks,stud);
        await _sender.SendEmailAsync(msg);
        return EmailStatus.Sent;
      }
       
      Message PrepareStatus(IEnumerable<ModuleTask> tasks,Student stud){
        StringBuilder sb = new StringBuilder();
        sb.Append($"Dear {stud.OtherNames},{Environment.NewLine}"+Environment.NewLine);
        sb.Append("As promised, here is your weekly outstanding summative discussions/portfolios:"+Environment.NewLine);
        foreach(var c in tasks){
          sb.Append(" - " +c.TaskName+Environment.NewLine);
        } 
        sb.Append(Environment.NewLine);
        sb.Append("Best wishes,"+Environment.NewLine);
        sb.Append("John"+Environment.NewLine);
        var recipient = "u"+stud.UniCode+"@unimail.hud.ac.uk";
        var subj = "XFX1061-2021 : Software Design > Weekly Status";
        var message = new Message(
          recipient, //recipient
          subj, // Subject
          sb.ToString(), //content
          null// IFormFileCollection
        );
        return message;
      }
    }
}
