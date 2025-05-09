from Acspy.Clients.SimpleClient import PySimpleClient
 
client = PySimpleClient()
 
hc = client.getComponent("Instrument")
print(hc.cameraOn())
print(hc.cameraOff())
print(hc.setPixelBias(10))
print(hc.setResetLevel(20))
#print(hc.takeImage(30))

