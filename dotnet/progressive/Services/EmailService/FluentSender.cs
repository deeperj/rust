using MimeKit;
using System;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using FluentEmail.Core;
using FluentEmail.Smtp;
using FluentEmail.Liquid;
using System.Net;
using System.Security;
using System.Diagnostics;
using System.Net.Mail;
using Newtonsoft.Json;
using Microsoft.Extensions.Options;


namespace EmailService
{
    public class FluentSender : IEmailSender
    {
        protected EmailConfiguration _emailConfig;
        public string Password { 
            set{
                var x =new SecureString();
                foreach (var item in value)
                {
                    x.AppendChar(item);
                }
                _emailConfig.Password=x;
            } 
        }

        public FluentSender(EmailConfiguration emailConfig)
        {
            _emailConfig = emailConfig;
        }

        public void SendEmail(Message message)
        {            
            var sender = new SmtpSender(() => new SmtpClient(_emailConfig.SmtpServer)
            {
                // Credentials = new NetworkCredential("john.alamina@gmail.com",x),
                Credentials = new NetworkCredential(_emailConfig.UserName,_emailConfig.Password),
                EnableSsl = true,
                DeliveryMethod = SmtpDeliveryMethod.Network,
                Port = _emailConfig.Port
            });

            Email.DefaultSender = sender;

            var email = Email
                .From(_emailConfig.UserName)
                .To(message.SendTo)
                .Subject(message.Subject)
                .Body(message.Content)
                .Send();
        }

        public async Task SendEmailAsync(Message message)
        {
          // Debug.WriteLine(JsonConvert.SerializeObject(message));
          var sender = new SmtpSender(() => new SmtpClient(_emailConfig.SmtpServer)
          {
              Credentials = new NetworkCredential(_emailConfig.UserName,_emailConfig.Password),
              EnableSsl = true,
              DeliveryMethod = SmtpDeliveryMethod.Network,
              Port = _emailConfig.Port
          });
          Email.DefaultSender = sender;
          Email.DefaultRenderer = new LiquidRenderer(Options.Create(new LiquidRendererOptions()));

          var email = await Email
              .From(_emailConfig.UserName)
              .To(message.SendTo)
              .Subject(message.Subject)
              .UsingTemplate(message.Content, new object())
              .SendAsync();
        }
    }
}
