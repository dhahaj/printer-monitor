#pragma once
#include <ESP8266WiFi.h>
#include "libs/ArduinoJson/ArduinoJson.h"
#include <base64.h>

class OctoPrintClient {

private:
  char myServer[100];
  int myPort = 80;
  String myApiKey = "";
  String encodedAuth = "";
  boolean pollPsu;

  void resetPrintData();
  boolean validate();
  WiFiClient getSubmitRequest(String apiGetData);
  WiFiClient getPostRequest(String apiPostData, String apiPostBody);
 
  String result;

  typedef struct {
    String averagePrintTime;
    String estimatedPrintTime;
    String fileName;
    String fileSize;
    String lastPrintTime;
    String progressCompletion;
    String progressFilepos;
    String progressPrintTime;
    String progressPrintTimeLeft;
    String state;
    String toolTemp;
    String toolTargetTemp;
    String filamentLength;
    String bedTemp;
    String bedTargetTemp;
    boolean isPrinting;
    boolean isPSUoff;
    String error;
  } PrinterStruct;

  PrinterStruct printerData;

  
public:
  OctoPrintClient(String ApiKey, String server, int port, String user, String pass, boolean psu);
  void getPrinterJobResults();
  void getPrinterPsuState();
  void updateOctoPrintClient(String ApiKey, String server, int port, String user, String pass, boolean psu);

  String getAveragePrintTime();
  String getEstimatedPrintTime();
  String getFileName();
  String getFileSize();
  String getLastPrintTime();
  String getProgressCompletion();
  String getProgressFilepos();
  String getProgressPrintTime();
  String getProgressPrintTimeLeft();
  String getState();
  boolean isPrinting();
  boolean isOperational();
  boolean isPSUoff();
  String getTempBedActual();
  String getTempBedTarget();
  String getTempToolActual();
  String getTempToolTarget();
  String getFilamentLength();
  String getValueRounded(String value);
  String getError();
};
