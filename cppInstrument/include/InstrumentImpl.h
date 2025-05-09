#ifndef _INSTRUMENT_COMPONENT_IMPL_H
#define _INSTRUMENT_COMPONENT_IMPL_H
 
#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif
 
//Base component implementation, including container services and component lifecycle infrastructure
#include <acscomponentImpl.h>
 
//Skeleton interface for server implementation
#include <InstrumentS.h>
 
//Error definitions for catching and raising exceptions
class InstrumentImpl : public virtual acscomponent::ACSComponentImpl, public virtual POA_INSTRUMENT_MODULE::Instrument {
private:
    bool isCameraOn = false;

public:
    InstrumentImpl(const ACE_CString& name, maci::ContainerServices * containerServices);
    virtual ~InstrumentImpl();
    void cameraOn();
    void cameraOff();
    TYPES::ImageType * takeImage(CORBA::Long exposureTime);
    void setRGB(TYPES::RGB const & rgbConfig);
    void setPixelBias(CORBA::Long bias);
    void setResetLevel(CORBA::Long resetLevel);
};
 
#endif

