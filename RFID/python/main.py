import serial                              # pip install pyserial
import mysql.connector as mysql            # pip install mysql.connector

ser = serial.Serial('COM3',9600)
mensagens = ['Nenhum card','Erro ao ler cartao/tag']

conexao = mysql.connect(
    host='ip/dns',
    user='user_database',
    password='senha_user_database',
    database='database'
)

cursor = conexao.cursor()

while True:
    try:
        if (ser.in_waiting >0):
            info = ser.readline().decode('utf-8').strip()
            rfid = str(info)
            print(rfid)
            if not (mensagens.__contains__(rfid)):
                sql = "INSERT INTO rfid(rfid_value,ativo) VALUES(%s,%s);"
                val = (rfid,1,)
                cursor.execute(sql,val)
                conexao.commit()
                
                print(f"Valor RFID: {rfid}")
                print("Info salva :) \n\n")
    except Exception as ex:
        print(f"Erro: {ex}")
        
    #cursor.close()
conexao.close()
ser.close()