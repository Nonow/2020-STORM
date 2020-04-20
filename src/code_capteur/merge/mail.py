import smtplib, ssl
from serial import Serial

"""
ser = Serial('COM3',9600)
ser.close()
ser.open()
data = ser.readline()
splt=data.split()

while True :
    print(splt)
"""
import serial

ser = serial.Serial('COM3', 9600)
while 1:
    line = ser.readline()
    if(line):
        SMTP_SERVER = 'mail.gmx.com'
        SMTP_PORT = 465

        sender = 'stormiot2@gmx.fr'
        password = 'storm123'
        recipient = 'sebastienwu0@gmail.com'

        subject = '[Storm]Intrusion !'
        body = 'Attention intrus détecté !'
        body = "" + body + ""
        headers = ["From: " + sender,
                   "Subject: " + subject,
                   "To: " + recipient,
                   "MIME-Version: 1.0",
                   "Content-Type: text/html; charset=utf-8"]
        headers = "\r\n".join(headers)
        message =  headers + "\r\n\r\n" + body

        context = ssl.create_default_context()
        with smtplib.SMTP_SSL(SMTP_SERVER, SMTP_PORT, context=context) as server:
            server.login(sender, password)
            server.sendmail(sender, recipient, message.encode("utf8"))
    pass
