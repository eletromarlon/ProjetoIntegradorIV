#include <ShiftOutMega.h> //Inclui a bilioteca ShiftOutMega.h
#include <virtuabotixRTC.h> //biblioteca para o RTC DS1302
#include <QList.h>

//Variáveis de uso dos registradores 74HC595


int latchPin = 3;  //Pino 8 conectado ao pino 12 do 74HC595 (Latch).
int dataPin = 2;  //Pino 11 conectado ao pino 14 do 74HC595 (Data).
int clockPin = 4; //Pino 12 conectado ao pino 11 do 74HC595 (Clock).

//Quantidade de registradores (74HC595). Para cada registrador, mais 8 saídas.
int qtdRegistradores = 5;

QList<int> filaCruzamento1;
QList<int> filaCruzamento2;
QList<int> filaCruzamento3;

int arrayInfoSemaforos1 [10][5];
int arrayInfoSemaforos2 [10][5];
int arrayInfoSemaforos3 [10][5];
int arrayInfoSemaforos4 [10][5];
int arrayInfoSemaforos5 [10][5];
int arrayInfoSemaforos6 [10][5];
int arrayInfoSemaforos7 [10][5];
int arrayInfoSemaforos8 [10][5];
int arrayInfoSemaforos9 [10][5];
int arrayInfoSemaforos10 [10][5];
int arrayInfoSemaforos11 [10][5];
int arrayInfoSemaforos12 [10][5];



ShiftOutMega mega(latchPin, dataPin, clockPin, qtdRegistradores); //Inicia a biblioteca passando os parametros de uso.     

#define   clk   5
#define   dat   6
#define   rst   7

#define pinS0 8
#define pinS1 9
#define pinS2 10
#define pinS3 11
#define pinAnalog A0

#define   segL       20
#define   minL       31
#define   horL       18
#define   d_semL      6
#define   d_mesL     30
#define   mesL       11
#define   anoL     2022

virtuabotixRTC   myRTC(clk, dat, rst);         //declara objeto para o RTC

int analogMultiplexerRead(byte portRead) {
    //Seleciona a porta
    digitalWrite(pinS0, bitRead(portRead, 0));
    digitalWrite(pinS1, bitRead(portRead, 1));
    digitalWrite(pinS2, bitRead(portRead, 2));
    digitalWrite(pinS3, bitRead(portRead, 3));
    
    //Lê o valor da porta
    return analogRead(pinAnalog);
}

int hora()
{
  myRTC.updateTime();         //faz leitura do DS1302
  return(myRTC.hours); 
} //end DS1302

int minuto()
{
  myRTC.updateTime();         //faz leitura do DS1302
  return(myRTC.minutes);  
} //end DS1302
int segundo()
{
  myRTC.updateTime();         //faz leitura do DS1302
  return(myRTC.seconds); 
}

int dia()
{
  myRTC.updateTime();         //faz leitura do DS1302
  return(myRTC.dayofmonth);  
} //end DS1302

int mes()
{
  myRTC.updateTime();         //faz leitura do DS1302
  return(myRTC.month);  
} //end DS1302

int ano()
{
  myRTC.updateTime();         //faz leitura do DS1302
  return(myRTC.year);  
} //end DS1302


void capturaDadosSemaforos(int sensor, int i)
{
  
  if(sensor == 0)
  {
    if(analogMultiplexerRead(0) > 970)
    {
      arrayInfoSemaforos4[i][0] = hora();
      arrayInfoSemaforos4[i][1] = 2;
      arrayInfoSemaforos4[i][2] = 1;
      arrayInfoSemaforos4[i][3] = minuto();
      arrayInfoSemaforos4[i][4] = segundo();

    } else {
      arrayInfoSemaforos4[i][0] = hora();
      arrayInfoSemaforos4[i][1] = 2;
      arrayInfoSemaforos4[i][2] = 0;
      arrayInfoSemaforos4[i][3] = minuto();
      arrayInfoSemaforos4[i][4] = segundo();

    }
  }
  else if(sensor == 1)
  {
    if(analogMultiplexerRead(1) > 970)
    {
      arrayInfoSemaforos1[i][0] = hora();
      arrayInfoSemaforos1[i][1] = 1;
      arrayInfoSemaforos1[i][2] = 1;
      arrayInfoSemaforos1[i][3] = minuto();
      arrayInfoSemaforos1[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos1[i][0] = hora();
      arrayInfoSemaforos1[i][1] = 1;
      arrayInfoSemaforos1[i][2] = 0;
      arrayInfoSemaforos1[i][3] = minuto();
      arrayInfoSemaforos1[i][4] = segundo();
      
    }
  }
  else if(sensor == 2)
  {
    if(analogMultiplexerRead(2) > 970)
    {
      arrayInfoSemaforos2[i][0] = hora();
      arrayInfoSemaforos2[i][1] = 3;
      arrayInfoSemaforos2[i][2] = 1;
      arrayInfoSemaforos2[i][3] = minuto();
      arrayInfoSemaforos2[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos2[i][0] = hora();
      arrayInfoSemaforos2[i][1] = 3;
      arrayInfoSemaforos2[i][2] = 0;
      arrayInfoSemaforos2[i][3] = minuto();
      arrayInfoSemaforos2[i][4] = segundo();
      
    }
  }
  else if(sensor == 3)
  {
    if(analogMultiplexerRead(3) > 970)
    {
      arrayInfoSemaforos3[i][0] = hora();
      arrayInfoSemaforos3[i][1] = 4;
      arrayInfoSemaforos3[i][2] = 1;
      arrayInfoSemaforos3[i][3] = minuto();
      arrayInfoSemaforos3[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos3[i][0] = hora();
      arrayInfoSemaforos3[i][1] = 4;
      arrayInfoSemaforos3[i][2] = 0;
      arrayInfoSemaforos3[i][3] = minuto();
      arrayInfoSemaforos3[i][4] = segundo();
      
    }
  }
  else if(sensor == 4)
  {
    if(analogMultiplexerRead(4) > 970)
    {
      arrayInfoSemaforos5[i][0] = hora();
      arrayInfoSemaforos5[i][1] = 5;
      arrayInfoSemaforos5[i][2] = 1;
      arrayInfoSemaforos5[i][3] = minuto();
      arrayInfoSemaforos5[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos5[i][0] = hora();
      arrayInfoSemaforos5[i][1] = 5;
      arrayInfoSemaforos5[i][2] = 0;
      arrayInfoSemaforos5[i][3] = minuto();
      arrayInfoSemaforos5[i][4] = segundo();
      
    }
  }
  else if(sensor == 5)
  {
    if(analogMultiplexerRead(5) > 970)
    {
      arrayInfoSemaforos8[i][0] = hora();
      arrayInfoSemaforos8[i][1] = 6;
      arrayInfoSemaforos8[i][2] = 1;
      arrayInfoSemaforos8[i][3] = minuto();
      arrayInfoSemaforos8[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos8[i][0] = hora();
      arrayInfoSemaforos8[i][1] = 6;
      arrayInfoSemaforos8[i][2] = 0;
      arrayInfoSemaforos8[i][3] = minuto();
      arrayInfoSemaforos8[i][4] = segundo();
      
    }
  }
  else if(sensor == 6)
  {
    if(analogMultiplexerRead(6) > 970)
    {
      arrayInfoSemaforos7[i][0] = hora();
      arrayInfoSemaforos7[i][1] = 8;
      arrayInfoSemaforos7[i][2] = 1;
      arrayInfoSemaforos7[i][3] = minuto();
      arrayInfoSemaforos7[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos7[i][0] = hora();
      arrayInfoSemaforos7[i][1] = 8;
      arrayInfoSemaforos7[i][2] = 0;
      arrayInfoSemaforos7[i][3] = minuto();
      arrayInfoSemaforos7[i][4] = segundo();
      
    }
  }
  else if(sensor == 15)
  {
    if(analogMultiplexerRead(15) > 970)
    {
      arrayInfoSemaforos11[i][0] = hora();
      arrayInfoSemaforos11[i][1] = 12;
      arrayInfoSemaforos11[i][2] = 1;
      arrayInfoSemaforos11[i][3] = minuto();
      arrayInfoSemaforos11[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos11[i][0] = hora();
      arrayInfoSemaforos11[i][1] = 12;
      arrayInfoSemaforos11[i][2] = 0;
      arrayInfoSemaforos11[i][3] = minuto();
      arrayInfoSemaforos11[i][4] = segundo();
      
    }
  }
  else if(sensor == 8)
  {
    if(analogMultiplexerRead(8) > 970)
    {
      arrayInfoSemaforos9[i][0] = hora();
      arrayInfoSemaforos9[i][1] = 9;
      arrayInfoSemaforos9[i][2] = 1;
      arrayInfoSemaforos9[i][3] = minuto();
      arrayInfoSemaforos9[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos9[i][0] = hora();
      arrayInfoSemaforos9[i][1] = 9;
      arrayInfoSemaforos9[i][2] = 0;
      arrayInfoSemaforos9[i][3] = minuto();
      arrayInfoSemaforos9[i][4] = segundo();
      
    }
  }
  else if(sensor == 9)
  {
    if(analogMultiplexerRead(9) > 570)
    {
      arrayInfoSemaforos10[i][0] = hora();
      arrayInfoSemaforos10[i][1] = 11;
      arrayInfoSemaforos10[i][2] = 1;
      arrayInfoSemaforos10[i][3] = minuto();
      arrayInfoSemaforos10[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos10[i][0] = hora();
      arrayInfoSemaforos10[i][1] = 11;
      arrayInfoSemaforos10[i][2] = 0;
      arrayInfoSemaforos10[i][3] = minuto();
      arrayInfoSemaforos10[i][4] = segundo();
      
    }
  }
  else if(sensor == 10)
  {
    if(analogMultiplexerRead(10) > 970)
    {
      arrayInfoSemaforos12[i][0] = hora();
      arrayInfoSemaforos12[i][1] = 10;
      arrayInfoSemaforos12[i][2] = 1;
      arrayInfoSemaforos12[i][3] = minuto();
      arrayInfoSemaforos12[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos12[i][0] = hora();
      arrayInfoSemaforos12[i][1] = 10;
      arrayInfoSemaforos12[i][2] = 0;
      arrayInfoSemaforos12[i][3] = minuto();
      arrayInfoSemaforos12[i][4] = segundo();
      
    }
  }
  else if(sensor == 11)
  {
    if(analogMultiplexerRead(11) > 1000)
    {
      arrayInfoSemaforos6[i][0] = hora();
      arrayInfoSemaforos6[i][1] = 7;
      arrayInfoSemaforos6[i][2] = 1;
      arrayInfoSemaforos6[i][3] = minuto();
      arrayInfoSemaforos6[i][4] = segundo();
      
    } else {
      arrayInfoSemaforos6[i][0] = hora();
      arrayInfoSemaforos6[i][1] = 7;
      arrayInfoSemaforos6[i][2] = 0;
      arrayInfoSemaforos6[i][3] = minuto();
      arrayInfoSemaforos6[i][4] = segundo();
      
    }
    
  }
}

int organizarAberturaDoSemaforo1()
{
  for(int i = 0; i < 10 ; i++)
  {
    int verifica = 0;
   
    /*if(arrayInfoSemaforos1[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento1.indexOf(arrayInfoSemaforos1[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento1.push_back(arrayInfoSemaforos1[i][1]);
        return 0;
      }
      verifica = 0;
    }
    if(arrayInfoSemaforos2[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento1.indexOf(arrayInfoSemaforos2[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento1.push_back(arrayInfoSemaforos2[i][1]);
        return 0;
      }
      verifica = 0;
    }
    if(arrayInfoSemaforos3[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento1.indexOf(arrayInfoSemaforos3[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento1.push_back(arrayInfoSemaforos3[i][1]);
        return 0;
      }
      verifica = 0;
    }*/
    if(arrayInfoSemaforos4[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento1.indexOf(arrayInfoSemaforos4[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento1.push_back(arrayInfoSemaforos4[i][1]);
        return 0;
      }
      verifica = 0;
    }



    
    /*if(arrayInfoSemaforos5[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento2.indexOf(arrayInfoSemaforos5[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento2.push_back(arrayInfoSemaforos5[i][1]);
        return 0;
      }
      verifica = 0;
    }
    if(arrayInfoSemaforos6[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento2.indexOf(arrayInfoSemaforos6[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento2.push_back(arrayInfoSemaforos6[i][1]);
        return 0;
      }
      verifica = 0;
    }
    if(arrayInfoSemaforos7[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento2.indexOf(arrayInfoSemaforos7[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento2.push_back(arrayInfoSemaforos7[i][1]);
        return 0;
      }
      verifica = 0;
    }
    if(arrayInfoSemaforos8[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento2.indexOf(arrayInfoSemaforos8[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento2.push_back(arrayInfoSemaforos8[i][1]);
        return 0;
      }
      verifica = 0;
    }




    if(arrayInfoSemaforos9[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento3.indexOf(arrayInfoSemaforos9[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento3.push_back(arrayInfoSemaforos9[i][1]);
        return 0;
      }
      verifica = 0;
    }
    if(arrayInfoSemaforos10[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento3.indexOf(arrayInfoSemaforos10[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento3.push_back(arrayInfoSemaforos10[i][1]);
        return 0;
      }
      verifica = 0;
    }
    if(arrayInfoSemaforos11[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento3.indexOf(arrayInfoSemaforos11[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento3.push_back(arrayInfoSemaforos11[i][1]);
        return 0;
      }
      verifica = 0;
    }
    if(arrayInfoSemaforos12[i][2] == 1)
    {
      for(int j = 0 ; j < 3 ; j++)
      {
        if(filaCruzamento3.indexOf(arrayInfoSemaforos12[i][1]) != -1 ){
          verifica = 1;
        }
      }

      if(verifica == 0)
      {
        filaCruzamento3.push_back(arrayInfoSemaforos12[i][1]);
        return 0;
      }
      verifica = 0;
    }*/
  }
}

 
void week(int dayW)
{  
  switch(dayW)
  {
    case 1: Serial.print("Dom"); break;
    case 2: Serial.print("Seg"); break;
    case 3: Serial.print("Ter"); break;
    case 4: Serial.print("Qua"); break;
    case 5: Serial.print("Qui"); break;
    case 6: Serial.print("Sex"); break;
    case 7: Serial.print("Sab"); break;
   
  } //end switch
  
}

void acenderCruzamento(
  int* semaforo1, int* semaforo2, int* semaforo3, int* semaforo4,
  int* semaforo5, int* semaforo6, int* semaforo7, int* semaforo8,
  int* semaforo9, int* semaforo10, int* semaforo11, int* semaforo12,
  int tempoDeAbertura){

   int tempo = tempoDeAbertura - (tempoDeAbertura*0.4);
   int tempoDelayVerde =  tempoDeAbertura*0.1;
   int tempoDelayAmarelo = tempoDelayVerde*0.1;
   
    
  /*
   * Cruzamento 1
   * Semaforo no verde: semaforo1, desligando amarelo
  */
  mega.shiftWrite(semaforo1[2], LOW);
  mega.shiftWrite(semaforo1[1], LOW);
  mega.shiftWrite(semaforo1[0], HIGH);

 /*
   * Cruzamento 2
   * Semaforo no verde: semaforo1, desligando amarelo
  */
  mega.shiftWrite(semaforo5[2], LOW);
  mega.shiftWrite(semaforo5[1], LOW);
  mega.shiftWrite(semaforo5[0], HIGH);

  /*
   * Cruzamento 3
   * Semaforo no verde: semaforo1, desligando amarelo
  */
  mega.shiftWrite(semaforo9[2], LOW);
  mega.shiftWrite(semaforo9[1], LOW);
  mega.shiftWrite(semaforo9[0], HIGH);

  /*
   * Cruzamento 1
   * Semaforos no vermelho: semaforo2, semaforo3, semaforo4
  */
  mega.shiftWrite(semaforo2[2], HIGH);
  mega.shiftWrite(semaforo3[2], HIGH);
  mega.shiftWrite(semaforo4[2], HIGH);
  
  /*
   * Cruzamento 2
   * Semaforos no vermelho: semaforo2, semaforo3, semaforo4
  */
  mega.shiftWrite(semaforo6[2], HIGH);
  mega.shiftWrite(semaforo7[2], HIGH);
  mega.shiftWrite(semaforo8[2], HIGH);
  
  /*
   * Cruzamento 3
   * Semaforos no vermelho: semaforo2, semaforo3, semaforo4
  */
  mega.shiftWrite(semaforo10[2], HIGH);
  mega.shiftWrite(semaforo11[2], HIGH);
  mega.shiftWrite(semaforo12[2], HIGH);

  /*SENSORES CAPTURANDO DADOS*/
  delay(tempoDelayVerde*3);
  /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo2[3], 0);
  capturaDadosSemaforos(semaforo3[3], 0);
  capturaDadosSemaforos(semaforo4[3], 0);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 0);
  capturaDadosSemaforos(semaforo7[3], 0);
  capturaDadosSemaforos(semaforo8[3], 0);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 0);
  capturaDadosSemaforos(semaforo11[3], 0);
  capturaDadosSemaforos(semaforo12[3], 0);

  delay(tempoDelayVerde);

   /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo2[3], 1);
  capturaDadosSemaforos(semaforo3[3], 1);
  capturaDadosSemaforos(semaforo4[3], 1);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 1);
  capturaDadosSemaforos(semaforo7[3], 1);
  capturaDadosSemaforos(semaforo8[3], 1);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 1);
  capturaDadosSemaforos(semaforo11[3], 1);
  capturaDadosSemaforos(semaforo12[3], 1);

  delay(tempoDelayVerde*5);

   /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo2[3], 2);
  capturaDadosSemaforos(semaforo3[3], 2);
  capturaDadosSemaforos(semaforo4[3], 2);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 2);
  capturaDadosSemaforos(semaforo7[3], 2);
  capturaDadosSemaforos(semaforo8[3], 2);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 2);
  capturaDadosSemaforos(semaforo11[3], 2);
  capturaDadosSemaforos(semaforo12[3], 2);

  delay(tempoDelayVerde);

   /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo2[3], 3);
  capturaDadosSemaforos(semaforo3[3], 3);
  capturaDadosSemaforos(semaforo4[3], 3);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 3);
  capturaDadosSemaforos(semaforo7[3], 3);
  capturaDadosSemaforos(semaforo8[3], 3);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 3);
  capturaDadosSemaforos(semaforo11[3], 3);
  capturaDadosSemaforos(semaforo12[3], 3);

  delay(tempoDelayVerde);

   /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo2[3], 4);
  capturaDadosSemaforos(semaforo3[3], 4);
  capturaDadosSemaforos(semaforo4[3], 4);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 4);
  capturaDadosSemaforos(semaforo7[3], 4);
  capturaDadosSemaforos(semaforo8[3], 4);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 4);
  capturaDadosSemaforos(semaforo11[3], 4);
  capturaDadosSemaforos(semaforo12[3], 4);

  delay(tempoDelayVerde);

 
  /*
   * Cruzamento 1
   * Semaforo no amarelo: semaforo1
  */
  mega.shiftWrite(semaforo1[0], LOW);
  mega.shiftWrite(semaforo1[1], HIGH);

  /*
   * Cruzamento 2
   * Semaforo no amarelo: semaforo1
  */
  mega.shiftWrite(semaforo5[0], LOW);
  mega.shiftWrite(semaforo5[1], HIGH);

  /*
   * Cruzamento 3
   * Semaforo no amarelo: semaforo1
  */
  mega.shiftWrite(semaforo9[0], LOW);
  mega.shiftWrite(semaforo9[1], HIGH);

  
  /**SENSORES CAPTURANDO DADOS*/
  /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  delay(tempoDelayAmarelo*5);
  capturaDadosSemaforos(semaforo2[3], 5);
  capturaDadosSemaforos(semaforo3[3], 5);
  capturaDadosSemaforos(semaforo4[3], 5);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 5);
  capturaDadosSemaforos(semaforo7[3], 5);
  capturaDadosSemaforos(semaforo8[3], 5);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 5);
  capturaDadosSemaforos(semaforo11[3], 5);
  capturaDadosSemaforos(semaforo12[3], 5);

  delay(tempoDelayAmarelo);

  /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo2[3], 6);
  capturaDadosSemaforos(semaforo3[3], 6);
  capturaDadosSemaforos(semaforo4[3], 6);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 6);
  capturaDadosSemaforos(semaforo7[3], 6);
  capturaDadosSemaforos(semaforo8[3], 6);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 6);
  capturaDadosSemaforos(semaforo11[3], 6);
  capturaDadosSemaforos(semaforo12[3], 6);

  delay(tempoDelayAmarelo);

  /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo2[3], 7);
  capturaDadosSemaforos(semaforo3[3], 7);
  capturaDadosSemaforos(semaforo4[3], 7);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 7);
  capturaDadosSemaforos(semaforo7[3], 7);
  capturaDadosSemaforos(semaforo8[3], 7);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 7);
  capturaDadosSemaforos(semaforo11[3], 7);
  capturaDadosSemaforos(semaforo12[3], 7);

  delay(tempoDelayAmarelo);

  /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo2[3], 8);
  capturaDadosSemaforos(semaforo3[3], 8);
  capturaDadosSemaforos(semaforo4[3], 8);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 8);
  capturaDadosSemaforos(semaforo7[3], 8);
  capturaDadosSemaforos(semaforo8[3], 8);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 8);
  capturaDadosSemaforos(semaforo11[3], 8);
  capturaDadosSemaforos(semaforo12[3], 8);

  delay(tempoDelayAmarelo);

  /**
   * Cruzamento 1 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo2[3], 9);
  capturaDadosSemaforos(semaforo3[3], 9);
  capturaDadosSemaforos(semaforo4[3], 9);

  /**
   * Cruzamento 2 
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo6[3], 9);
  capturaDadosSemaforos(semaforo7[3], 9);
  capturaDadosSemaforos(semaforo8[3], 9);
  
  /**
   * Cruzamento 3
   * Sensores capturando dados
  */
  capturaDadosSemaforos(semaforo10[3], 9);
  capturaDadosSemaforos(semaforo11[3], 9);
  capturaDadosSemaforos(semaforo12[3], 9);

  delay(tempoDelayAmarelo);

  

  /*
   * Cruzamento 1
   * Ligar vermelho
  */
  mega.shiftWrite(semaforo1[1], LOW);
  mega.shiftWrite(semaforo1[2], HIGH);

  /*
   * Cruzamento 2
   * Ligar vermelho
  */
  mega.shiftWrite(semaforo5[1], LOW);
  mega.shiftWrite(semaforo5[2], HIGH);

  /*
   * Cruzamento 3
   * Ligar vermelho
  */
  mega.shiftWrite(semaforo9[1], LOW);
  mega.shiftWrite(semaforo9[2], HIGH);
  
  delay(1500);
  mega.shiftWrite(semaforo1[2], LOW);
  mega.shiftWrite(semaforo5[2], LOW);
  mega.shiftWrite(semaforo9[2], LOW);

  

}

void ordemCruzamento(int ordem1, int ordem2, int ordem3, int* semaforosCruzamento1, int* semaforosCruzamento2, int* semaforosCruzamento3, int tempoDeAbertura)
{
  
  if(ordem1 == 1 && ordem2 == 1 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 1 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 1 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 1 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 1 && ordem2 == 2 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 2 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 2 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 2 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 1 && ordem2 == 3 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 3 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 3 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2],
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 3 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 1 && ordem2 == 4 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 4 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 4 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 1 && ordem2 == 4 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 2 && ordem2 == 1 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 1 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3],
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 1 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 1 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 2 && ordem2 == 2 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 2 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 2 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 2 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 2 && ordem2 == 3 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 3 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 3 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 3 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }

  else if(ordem1 == 2 && ordem2 == 4 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 4 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 4 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 2 && ordem2 == 4 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[2], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 3 && ordem2 == 1 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 1 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3],
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 1 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 1 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 3 && ordem2 == 2 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 2 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 2 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 2 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 3 && ordem2 == 3 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 3 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 3 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 3 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }

  else if(ordem1 == 3 && ordem2 == 4 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 4 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 4 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 3 && ordem2 == 4 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[3], semaforosCruzamento1[0], semaforosCruzamento1[1], semaforosCruzamento1[2], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }

  else if(ordem1 == 4 && ordem2 == 1 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 1 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3],
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 1 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 1 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 4 && ordem2 == 2 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 2 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 2 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 2 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[2], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
  else if(ordem1 == 4 && ordem2 == 3 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 3 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 3 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 3 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[3], semaforosCruzamento2[0], semaforosCruzamento2[1], semaforosCruzamento2[2], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }

  else if(ordem1 == 4 && ordem2 == 4 && ordem3 == 1){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 4 && ordem3 == 2){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[2], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 4 && ordem3 == 3){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[3], semaforosCruzamento3[0], semaforosCruzamento3[1], semaforosCruzamento3[2], 
      tempoDeAbertura);
  }
  else if(ordem1 == 4 && ordem2 == 4 && ordem3 == 4){
    acenderCruzamento(
      semaforosCruzamento1[1], semaforosCruzamento1[0], semaforosCruzamento1[2], semaforosCruzamento1[3], 
      semaforosCruzamento2[1], semaforosCruzamento2[0], semaforosCruzamento2[2], semaforosCruzamento2[3], 
      semaforosCruzamento3[1], semaforosCruzamento3[0], semaforosCruzamento3[2], semaforosCruzamento3[3], 
      tempoDeAbertura);
  }
  
}

void setup(){
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(A5,INPUT);

  pinMode(pinS0, OUTPUT);
  pinMode(pinS1, OUTPUT);
  pinMode(pinS2, OUTPUT);
  pinMode(pinS3, OUTPUT);

  filaCruzamento1.clear();
  filaCruzamento2.clear();
  filaCruzamento3.clear();
  
  Serial.begin(9600);
}

void loop(){

  int semaforo1[] = {1, 2, 3, 1};
  int semaforo2[] = {4, 5, 6, 0};
  int semaforo3[] = {19, 20, 21, 2};
  int semaforo4[] = {22, 23, 24, 3};
  
  int semaforo5[] = {7, 8, 9, 4};
  int semaforo6[] = {10, 11, 12, 5};
  int semaforo7[] = {25, 26, 27, 11};
  int semaforo8[] = {28, 29, 30, 6};
  
  int semaforo9[] = {13, 14, 15, 8};
  int semaforo10[] = {16, 17, 18, 10};
  int semaforo11[] = {31, 32, 33, 9};
  int semaforo12[] = {34, 35, 36, 15};

  int semaforosCruzamento1[4] = {semaforo1, semaforo2, semaforo3, semaforo4};
  int semaforosCruzamento2[4] = {semaforo5, semaforo6, semaforo7, semaforo8};
  int semaforosCruzamento3[4] = {semaforo9, semaforo10, semaforo11, semaforo12};

  int ordemC1 = 1;
  int ordemC2 = 1;
  int ordemC3 = 1;

  //myRTC.setDS1302Time(segL, minL, horL, d_semL, d_mesL, mesL, anoL);
  //pop_front();
  
  if(hora() > 22 && hora() < 5)
  {
    ordemCruzamento(1, 1, 1, semaforosCruzamento1, semaforosCruzamento2, semaforosCruzamento3, 5000);
    ordemCruzamento(2, 2, 2, semaforosCruzamento1, semaforosCruzamento2, semaforosCruzamento3, 5000);
    ordemCruzamento(3, 3, 3, semaforosCruzamento1, semaforosCruzamento2, semaforosCruzamento3, 5000);
    ordemCruzamento(4, 4, 4, semaforosCruzamento1, semaforosCruzamento2, semaforosCruzamento3, 5000);
  }else
  {
    ordemCruzamento(ordemC1, ordemC2, ordemC3, semaforosCruzamento1, semaforosCruzamento2, semaforosCruzamento3, 10000); //1,1,1
    
    organizarAberturaDoSemaforo1();
    Serial.println(filaCruzamento1.front());
    Serial.println(filaCruzamento2.front());
    Serial.println(filaCruzamento3.front());
    if(filaCruzamento1.front() == 4){
      
      ordemC1 = 3;
      filaCruzamento1.pop_front();
      
    } else if(filaCruzamento1.front() == 3){
      
      ordemC1 = 2;
      filaCruzamento1.pop_front();
      
    } else if(filaCruzamento1.front() == 2){
      
      ordemC1 = 4;
      filaCruzamento1.pop_front();
      
    }else if(filaCruzamento1.front() == 1){
      
      ordemC1 = 1;
      filaCruzamento1.pop_front();
      
    }else{
      
      ordemC1 += 1;
    }
    
    if(filaCruzamento2.front() == 7){
      
      ordemC2 = 2;
      filaCruzamento2.pop_front();
      
    } else if(filaCruzamento2.front() == 8){
      
      ordemC2 = 3;
      filaCruzamento2.pop_front();
      
    } else if(filaCruzamento2.front() == 6){
      
      ordemC2 = 4;
      filaCruzamento2.pop_front();
      
    }else if(filaCruzamento2.front() == 5){
      
      ordemC2 = 1;
      filaCruzamento2.pop_front();
      
    }else{
      
      ordemC2 += 1;
    }
    
    if(filaCruzamento3.front() == 11){
      
      ordemC3 = 2;
      filaCruzamento3.pop_front();
      
    } else if(filaCruzamento3.front() == 10){
      
      ordemC3 = 3;
      filaCruzamento3.pop_front();
      
    } else if(filaCruzamento3.front() == 12){
      
      ordemC3 = 4;
      filaCruzamento3.pop_front();
      
    }else if(filaCruzamento3.front() == 9){
      
      ordemC3 = 1;
      filaCruzamento3.pop_front();
      
    }else{
      
      ordemC3 += 1;
    }

    ordemCruzamento(ordemC1, ordemC2, ordemC3, semaforosCruzamento1, semaforosCruzamento2, semaforosCruzamento3, 10000);
    
    organizarAberturaDoSemaforo1();
    Serial.println(filaCruzamento1.front());
    Serial.println(filaCruzamento2.front());
    Serial.println(filaCruzamento3.front());
    if(filaCruzamento1.front() == 4){
      
      ordemC1 = 3;
      filaCruzamento1.pop_front();
      
    } else if(filaCruzamento1.front() == 3){
      
      ordemC1 = 2;
      filaCruzamento1.pop_front();
      
    } else if(filaCruzamento1.front() == 2){
      
      ordemC1 = 4;
      filaCruzamento1.pop_front();
      
    }else if(filaCruzamento1.front() == 1){
      
      ordemC1 = 1;
      filaCruzamento1.pop_front();
      
    }else{
      
      ordemC1 += 1;
    }
    
    if(filaCruzamento2.front() == 7){
      
      ordemC2 = 2;
      filaCruzamento2.pop_front();
      
    } else if(filaCruzamento2.front() == 8){
      
      ordemC2 = 3;
      filaCruzamento2.pop_front();
      
    } else if(filaCruzamento2.front() == 6){
      
      ordemC2 = 4;
      filaCruzamento2.pop_front();
      
    }else if(filaCruzamento2.front() == 5){
      
      ordemC2 = 1;
      filaCruzamento2.pop_front();
      
    }else{
      
      ordemC2 += 1;
    }
    
    if(filaCruzamento3.front() == 11){
      
      ordemC3 = 2;
      filaCruzamento3.pop_front();
      
    } else if(filaCruzamento3.front() == 10){
      
      ordemC3 = 3;
      filaCruzamento3.pop_front();
      
    } else if(filaCruzamento3.front() == 12){
      
      ordemC3 = 4;
      filaCruzamento3.pop_front();
      
    }else if(filaCruzamento3.front() == 9){
      
      ordemC3 = 1;
      filaCruzamento3.pop_front();
      
    }else{
      
      ordemC3 += 1;
    }

    ordemCruzamento(ordemC1, ordemC2, ordemC3, semaforosCruzamento1, semaforosCruzamento2, semaforosCruzamento3, 10000);


    organizarAberturaDoSemaforo1();
    Serial.println(filaCruzamento1.front());
    Serial.println(filaCruzamento2.front());
    Serial.println(filaCruzamento3.front());
    if(filaCruzamento1.front() == 4){
      
      ordemC1 = 3;
      filaCruzamento1.pop_front();
      
    } else if(filaCruzamento1.front() == 3){
      
      ordemC1 = 2;
      filaCruzamento1.pop_front();
      
    } else if(filaCruzamento1.front() == 2){
      
      ordemC1 = 4;
      filaCruzamento1.pop_front();
      
    }else if(filaCruzamento1.front() == 1){
      
      ordemC1 = 1;
      filaCruzamento1.pop_front();
      
    }else{
      
      ordemC1 += 1;
    }
    
    if(filaCruzamento2.front() == 7){
      
      ordemC2 = 2;
      filaCruzamento2.pop_front();
      
    } else if(filaCruzamento2.front() == 8){
      
      ordemC2 = 3;
      filaCruzamento2.pop_front();
      
    } else if(filaCruzamento2.front() == 6){
      
      ordemC2 = 4;
      filaCruzamento2.pop_front();
      
    }else if(filaCruzamento2.front() == 5){
      
      ordemC2 = 1;
      filaCruzamento2.pop_front();
      
    }else{
      
      ordemC2 += 1;
    }
    
    if(filaCruzamento3.front() == 11){
      
      ordemC3 = 2;
      filaCruzamento3.pop_front();
      
    } else if(filaCruzamento3.front() == 10){
      
      ordemC3 = 3;
      filaCruzamento3.pop_front();
      
    } else if(filaCruzamento3.front() == 12){
      
      ordemC3 = 4;
      filaCruzamento3.pop_front();
      
    }else if(filaCruzamento3.front() == 9){
      
      ordemC3 = 1;
      filaCruzamento3.pop_front();
      
    }else{
      
      ordemC3 += 1;
    }

    ordemCruzamento(ordemC1, ordemC2, ordemC3, semaforosCruzamento1, semaforosCruzamento2, semaforosCruzamento3, 10000);

    
  }

}
