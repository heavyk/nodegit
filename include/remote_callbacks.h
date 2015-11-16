#ifndef GITREMOTECALLBACKS_H
#define GITREMOTECALLBACKS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/cred.h"
  #include "../include/cert.h"
  #include "../include/transfer_progress.h"
 
using namespace node;
using namespace v8;

class GitRemoteCallbacks : public Nan::ObjectWrap {
  public:
    GitRemoteCallbacks(git_remote_callbacks* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_remote_callbacks *GetValue();
    git_remote_callbacks **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

            static int credentials_cppCallback (
              git_cred ** cred
                ,
               const char * url
                ,
               const char * username_from_url
                ,
               unsigned int allowed_types
                ,
               void * payload
            );

          static void credentials_async(uv_async_t* req, int status);
          static void credentials_setupAsyncPromisePolling(uv_async_t* req);
          static void credentials_asyncPromisePolling(uv_async_t* req, int status);
          struct CredentialsBaton {
              git_cred ** cred;
              const char * url;
              const char * username_from_url;
              unsigned int allowed_types;
              void * payload;
 
            uv_async_t req;
            int result;
            Nan::Persistent<Object> promise;
            bool done;
          };
            static int certificate_check_cppCallback (
              git_cert * cert
                ,
               int valid
                ,
               const char * host
                ,
               void * payload
            );

          static void certificate_check_async(uv_async_t* req, int status);
          static void certificate_check_setupAsyncPromisePolling(uv_async_t* req);
          static void certificate_check_asyncPromisePolling(uv_async_t* req, int status);
          struct CertificateCheckBaton {
              git_cert * cert;
              int valid;
              const char * host;
              void * payload;
 
            uv_async_t req;
            int result;
            Nan::Persistent<Object> promise;
            bool done;
          };
            static int transfer_progress_cppCallback (
              const git_transfer_progress * stats
                ,
               void * payload
            );

          static void transfer_progress_async(uv_async_t* req, int status);
          static void transfer_progress_setupAsyncPromisePolling(uv_async_t* req);
          static void transfer_progress_asyncPromisePolling(uv_async_t* req, int status);
          struct TransferProgressBaton {
              const git_transfer_progress * stats;
              void * payload;
 
            uv_async_t req;
            int result;
            Nan::Persistent<Object> promise;
            bool done;
          };
     
  private:
    GitRemoteCallbacks();
    ~GitRemoteCallbacks();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

             Nan::Callback* credentials;
  
        static NAN_GETTER(GetCredentials);
        static NAN_SETTER(SetCredentials);

             Nan::Callback* certificate_check;
  
        static NAN_GETTER(GetCertificateCheck);
        static NAN_SETTER(SetCertificateCheck);

             Nan::Callback* transfer_progress;
  
        static NAN_GETTER(GetTransferProgress);
        static NAN_SETTER(SetTransferProgress);

             Nan::Persistent<Value> payload;
  
        static NAN_GETTER(GetPayload);
        static NAN_SETTER(SetPayload);

  
    git_remote_callbacks *raw;
};

#endif
