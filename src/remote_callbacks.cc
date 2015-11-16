// This is a generated file, modify: generate/templates/struct_content.cc.
#include <nan.h>
#include <string.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

extern "C" {
  #include <git2.h>
 }

#include <iostream>
#include "../include/functions/copy.h"
#include "../include/remote_callbacks.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/cred.h"
  #include "../include/cert.h"
  #include "../include/transfer_progress.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitRemoteCallbacks::GitRemoteCallbacks() {
   git_remote_callbacks wrappedValue = GIT_REMOTE_CALLBACKS_INIT;
   this->raw = (git_remote_callbacks*) malloc(sizeof(git_remote_callbacks));
  memcpy(this->raw, &wrappedValue, sizeof(git_remote_callbacks));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitRemoteCallbacks::GitRemoteCallbacks(git_remote_callbacks* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitRemoteCallbacks::~GitRemoteCallbacks() {
     if (this->credentials != NULL) {
    delete this->credentials;
    this->raw->payload = NULL;
  }
     if (this->certificate_check != NULL) {
    delete this->certificate_check;
    this->raw->payload = NULL;
  }
     if (this->transfer_progress != NULL) {
    delete this->transfer_progress;
    this->raw->payload = NULL;
  }
         
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitRemoteCallbacks::ConstructFields() {
   
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->credentials = NULL;
          this->raw->payload = (void *)this;
          this->credentials = NULL;
   
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->certificate_check = NULL;
          this->raw->payload = (void *)this;
          this->certificate_check = NULL;
   
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->transfer_progress = NULL;
          this->raw->payload = (void *)this;
          this->transfer_progress = NULL;
   
          Local<Value> payload = Nan::Undefined();
          this->payload.Reset(payload);
    }

void GitRemoteCallbacks::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("RemoteCallbacks").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("credentials").ToLocalChecked(), GetCredentials, SetCredentials);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("certificateCheck").ToLocalChecked(), GetCertificateCheck, SetCertificateCheck);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("transferProgress").ToLocalChecked(), GetTransferProgress, SetTransferProgress);
     
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("RemoteCallbacks").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitRemoteCallbacks::JSNewFunction) {
  GitRemoteCallbacks* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitRemoteCallbacks();
  }
  else {
    instance = new GitRemoteCallbacks(static_cast<git_remote_callbacks*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitRemoteCallbacks::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitRemoteCallbacks::constructor_template), 2, argv).ToLocalChecked());
}

git_remote_callbacks *GitRemoteCallbacks::GetValue() {
  return this->raw;
}

git_remote_callbacks **GitRemoteCallbacks::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitRemoteCallbacks::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitRemoteCallbacks::GetVersion) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitRemoteCallbacks::SetVersion) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitRemoteCallbacks::GetCredentials) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        if (wrapper->credentials != NULL) {
          info.GetReturnValue().Set(wrapper->credentials->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitRemoteCallbacks::SetCredentials) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        if (wrapper->credentials != NULL) {
          delete wrapper->credentials;
        }

        if (value->IsFunction()) {
          if (!wrapper->raw->credentials) {
            wrapper->raw->credentials = (git_cred_acquire_cb)credentials_cppCallback;
          }

          wrapper->credentials = new Nan::Callback(value.As<Function>());
        }

     }

      int GitRemoteCallbacks::credentials_cppCallback (
          git_cred ** cred,           const char * url,           const char * username_from_url,           unsigned int allowed_types,           void * payload        ) {
        CredentialsBaton* baton = new CredentialsBaton();

          baton->cred = cred;
          baton->url = url;
          baton->username_from_url = username_from_url;
          baton->allowed_types = allowed_types;
          baton->payload = payload;
 
        baton->result = 0;
        baton->req.data = baton;
        baton->done = false;

        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) credentials_async);
        uv_async_send(&baton->req);

        while(!baton->done) {
          sleep_for_ms(1);
        }

          *cred = *baton->cred;
  
        return baton->result;
      }

      void GitRemoteCallbacks::credentials_async(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        CredentialsBaton* baton = static_cast<CredentialsBaton*>(req->data);
        GitRemoteCallbacks* instance = static_cast<GitRemoteCallbacks*>(baton->    payload  );

        if (instance->credentials->IsEmpty()) {
            baton->result = 1; // no results acquired
 
          baton->done = true;
          return;
        }

           if (baton->url == NULL) {
              baton->url = "";
          }
            if (baton->username_from_url == NULL) {
              baton->username_from_url = "";
          }
      
        Local<Value> argv[4] = {
                 Nan::New(baton->url).ToLocalChecked(),
                  Nan::New(baton->username_from_url).ToLocalChecked(),
                   Nan::New(baton->allowed_types),
                Nan::New(instance->payload)
          };

        Nan::TryCatch tryCatch;
        Local<v8::Value> result = instance->credentials->Call(4, argv);

        if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
          Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

          if (thenProp->IsFunction()) {
            // we can be reasonbly certain that the result is a promise
            Local<Object> promise = result->ToObject();

            baton->promise.Reset(promise);

            uv_close((uv_handle_t*) &baton->req, (uv_close_cb) credentials_setupAsyncPromisePolling);
            return;
          }
        }

          if (result.IsEmpty() || result->IsNativeError()) {
            baton->result = -1;
          }
          else if (!result->IsNull() && !result->IsUndefined()) {
            GitCred* wrapper = Nan::ObjectWrap::Unwrap<GitCred>(result->ToObject());
            wrapper->selfFreeing = false;

            baton->cred = wrapper->GetRefValue();
            baton->result = 0;
           }
          else {
            baton->result = 1;
          }
         baton->done = true;
        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      void GitRemoteCallbacks::credentials_setupAsyncPromisePolling(uv_async_t* req) {
        CredentialsBaton* baton = static_cast<CredentialsBaton*>(req->data);
        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) credentials_asyncPromisePolling);
        uv_async_send(&baton->req);
      }

      void GitRemoteCallbacks::credentials_asyncPromisePolling(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        CredentialsBaton* baton = static_cast<CredentialsBaton*>(req->data);
        Local<Object> promise = Nan::New<Object>(baton->promise);

        Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
        Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

        if (isPending->Value()) {
          uv_async_send(&baton->req);
          return;
        }

        Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

        if (isFulfilled->Value()) {
          Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> result = resultFn->Call(promise, 0, argv);

            if (result.IsEmpty() || result->IsNativeError()) {
              baton->result = -1;
            }
            else if (!result->IsNull() && !result->IsUndefined()) {
              GitCred* wrapper = Nan::ObjectWrap::Unwrap<GitCred>(result->ToObject());
              wrapper->selfFreeing = false;

              baton->cred = wrapper->GetRefValue();
              baton->result = 0;
             }
            else {
              baton->result = 1;
            }
           baton->done = true;
        }
        else {
          // promise was rejected
          GitRemoteCallbacks* instance = static_cast<GitRemoteCallbacks*>(baton->    payload  );
          Local<v8::Object> parent = instance->handle();
          Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
          parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

          baton->result = -1;
          baton->done = true;
        }

        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      NAN_GETTER(GitRemoteCallbacks::GetCertificateCheck) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        if (wrapper->certificate_check != NULL) {
          info.GetReturnValue().Set(wrapper->certificate_check->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitRemoteCallbacks::SetCertificateCheck) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        if (wrapper->certificate_check != NULL) {
          delete wrapper->certificate_check;
        }

        if (value->IsFunction()) {
          if (!wrapper->raw->certificate_check) {
            wrapper->raw->certificate_check = (git_transport_certificate_check_cb)certificate_check_cppCallback;
          }

          wrapper->certificate_check = new Nan::Callback(value.As<Function>());
        }

     }

      int GitRemoteCallbacks::certificate_check_cppCallback (
          git_cert * cert,           int valid,           const char * host,           void * payload        ) {
        CertificateCheckBaton* baton = new CertificateCheckBaton();

          baton->cert = cert;
          baton->valid = valid;
          baton->host = host;
          baton->payload = payload;
 
        baton->result = 0;
        baton->req.data = baton;
        baton->done = false;

        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) certificate_check_async);
        uv_async_send(&baton->req);

        while(!baton->done) {
          sleep_for_ms(1);
        }

  
        return baton->result;
      }

      void GitRemoteCallbacks::certificate_check_async(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(req->data);
        GitRemoteCallbacks* instance = static_cast<GitRemoteCallbacks*>(baton->   payload  );

        if (instance->certificate_check->IsEmpty()) {
            baton->result = 1; // no results acquired
 
          baton->done = true;
          return;
        }

              if (baton->host == NULL) {
              baton->host = "";
          }
    
        Local<Value> argv[4] = {
                GitCert::New((void *)baton->cert, false),
                   Nan::New(baton->valid),
                  Nan::New(baton->host).ToLocalChecked(),
                Nan::New(instance->payload)
          };

        Nan::TryCatch tryCatch;
        Local<v8::Value> result = instance->certificate_check->Call(4, argv);

        if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
          Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

          if (thenProp->IsFunction()) {
            // we can be reasonbly certain that the result is a promise
            Local<Object> promise = result->ToObject();

            baton->promise.Reset(promise);

            uv_close((uv_handle_t*) &baton->req, (uv_close_cb) certificate_check_setupAsyncPromisePolling);
            return;
          }
        }

          if (result.IsEmpty() || result->IsNativeError()) {
            baton->result = -1;
          }
          else if (!result->IsNull() && !result->IsUndefined()) {
             if (result->IsNumber()) {
              baton->result = (int)result->ToNumber()->Value();
            }
            else {
              baton->result = 1;
            }
           }
          else {
            baton->result = 1;
          }
         baton->done = true;
        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      void GitRemoteCallbacks::certificate_check_setupAsyncPromisePolling(uv_async_t* req) {
        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(req->data);
        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) certificate_check_asyncPromisePolling);
        uv_async_send(&baton->req);
      }

      void GitRemoteCallbacks::certificate_check_asyncPromisePolling(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(req->data);
        Local<Object> promise = Nan::New<Object>(baton->promise);

        Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
        Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

        if (isPending->Value()) {
          uv_async_send(&baton->req);
          return;
        }

        Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

        if (isFulfilled->Value()) {
          Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> result = resultFn->Call(promise, 0, argv);

            if (result.IsEmpty() || result->IsNativeError()) {
              baton->result = -1;
            }
            else if (!result->IsNull() && !result->IsUndefined()) {
               if (result->IsNumber()) {
                baton->result = (int)result->ToNumber()->Value();
              }
              else{
                baton->result = 1;
              }
             }
            else {
              baton->result = 1;
            }
           baton->done = true;
        }
        else {
          // promise was rejected
          GitRemoteCallbacks* instance = static_cast<GitRemoteCallbacks*>(baton->   payload  );
          Local<v8::Object> parent = instance->handle();
          Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
          parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

          baton->result = -1;
          baton->done = true;
        }

        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      NAN_GETTER(GitRemoteCallbacks::GetTransferProgress) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        if (wrapper->transfer_progress != NULL) {
          info.GetReturnValue().Set(wrapper->transfer_progress->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitRemoteCallbacks::SetTransferProgress) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        if (wrapper->transfer_progress != NULL) {
          delete wrapper->transfer_progress;
        }

        if (value->IsFunction()) {
          if (!wrapper->raw->transfer_progress) {
            wrapper->raw->transfer_progress = (git_transfer_progress_cb)transfer_progress_cppCallback;
          }

          wrapper->transfer_progress = new Nan::Callback(value.As<Function>());
        }

     }

      int GitRemoteCallbacks::transfer_progress_cppCallback (
          const git_transfer_progress * stats,           void * payload        ) {
        TransferProgressBaton* baton = new TransferProgressBaton();

          baton->stats = stats;
          baton->payload = payload;
 
        baton->result = 0;
        baton->req.data = baton;
        baton->done = false;

        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) transfer_progress_async);
        uv_async_send(&baton->req);

        while(!baton->done) {
          sleep_for_ms(1);
        }

  
        return baton->result;
      }

      void GitRemoteCallbacks::transfer_progress_async(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        TransferProgressBaton* baton = static_cast<TransferProgressBaton*>(req->data);
        GitRemoteCallbacks* instance = static_cast<GitRemoteCallbacks*>(baton-> payload  );

        if (instance->transfer_progress->IsEmpty()) {
            baton->result = 0; // no results acquired
 
          baton->done = true;
          return;
        }

    
        Local<Value> argv[2] = {
                GitTransferProgress::New((void *)baton->stats, false),
                Nan::New(instance->payload)
          };

        Nan::TryCatch tryCatch;
        Local<v8::Value> result = instance->transfer_progress->Call(2, argv);

        if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
          Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

          if (thenProp->IsFunction()) {
            // we can be reasonbly certain that the result is a promise
            Local<Object> promise = result->ToObject();

            baton->promise.Reset(promise);

            uv_close((uv_handle_t*) &baton->req, (uv_close_cb) transfer_progress_setupAsyncPromisePolling);
            return;
          }
        }

          if (result.IsEmpty() || result->IsNativeError()) {
            baton->result = -1;
          }
          else if (!result->IsNull() && !result->IsUndefined()) {
             if (result->IsNumber()) {
              baton->result = (int)result->ToNumber()->Value();
            }
            else {
              baton->result = 0;
            }
           }
          else {
            baton->result = 0;
          }
         baton->done = true;
        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      void GitRemoteCallbacks::transfer_progress_setupAsyncPromisePolling(uv_async_t* req) {
        TransferProgressBaton* baton = static_cast<TransferProgressBaton*>(req->data);
        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) transfer_progress_asyncPromisePolling);
        uv_async_send(&baton->req);
      }

      void GitRemoteCallbacks::transfer_progress_asyncPromisePolling(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        TransferProgressBaton* baton = static_cast<TransferProgressBaton*>(req->data);
        Local<Object> promise = Nan::New<Object>(baton->promise);

        Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
        Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

        if (isPending->Value()) {
          uv_async_send(&baton->req);
          return;
        }

        Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

        if (isFulfilled->Value()) {
          Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> result = resultFn->Call(promise, 0, argv);

            if (result.IsEmpty() || result->IsNativeError()) {
              baton->result = -1;
            }
            else if (!result->IsNull() && !result->IsUndefined()) {
               if (result->IsNumber()) {
                baton->result = (int)result->ToNumber()->Value();
              }
              else{
                baton->result = 0;
              }
             }
            else {
              baton->result = 0;
            }
           baton->done = true;
        }
        else {
          // promise was rejected
          GitRemoteCallbacks* instance = static_cast<GitRemoteCallbacks*>(baton-> payload  );
          Local<v8::Object> parent = instance->handle();
          Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
          parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

          baton->result = -1;
          baton->done = true;
        }

        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      NAN_GETTER(GitRemoteCallbacks::GetPayload) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->payload));

     }

    NAN_SETTER(GitRemoteCallbacks::SetPayload) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        wrapper->payload.Reset(value);

     }

   
Nan::Persistent<Function> GitRemoteCallbacks::constructor_template;
