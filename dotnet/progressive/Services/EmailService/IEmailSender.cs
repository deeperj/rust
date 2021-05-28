using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace EmailService
{
    public interface IEmailSender
    {
        string Password
        {
            set;
        }
        void SendEmail(Message message);
        Task SendEmailAsync(Message message);
    }
}
