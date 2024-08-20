import serial
import mysql.connector as mysql

ser = serial.Serial('COM3',9600)
mensagens = ['Nenhum card','Erro ao ler cartao/tag']

conexao = mysql.connect(
    host='192.168.1.105',
    user='root',
    password='wrede',
    database='rfid2'
)

cursor = conexao.cursor()

while True:
    try:
        if (ser.in_waiting >0):
            info = ser.readline().decode('utf-8').strip()
            rfid = str(info)
            print(rfid)

            sql = "INSERT INTO rfid_date(valor_tag_rfid) VALUES(%s)"
            val = (rfid,)
            cursor.execute(sql,val)
            conexao.commit()
            
            print(f"Valor RFID: {rfid}")
            print("Info salva :) \n\n")
    except Exception as ex:
        print(f"Erro: {ex}")
        
    #cursor.close()
conexao.close()
ser.close()