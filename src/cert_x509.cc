// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/cert_x509.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/wrapper.h"
  #include "node_buffer.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCertX509::GitCertX509(git_cert_x509 *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitCertX509::~GitCertX509() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCertX509::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("CertX509").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "certType", CertType);
         Nan::SetPrototypeMethod(tpl, "data", Data);
         Nan::SetPrototypeMethod(tpl, "len", Len);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("CertX509").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitCertX509::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitCertX509 cannot be instantiated.");
     }

    GitCertX509* object = new GitCertX509(static_cast<git_cert_x509 *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitCertX509::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitCertX509::constructor_template), 2, argv).ToLocalChecked());
  }

  git_cert_x509 *GitCertX509::GetValue() {
    return this->raw;
  }

  git_cert_x509 **GitCertX509::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitCertX509::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitCertX509::CertType) {
      Local<v8::Value> to;

       git_cert_t
         cert_type =
         Nan::ObjectWrap::Unwrap<GitCertX509>(info.This())->GetValue()->cert_type;
 // start convert_to_v8 block
     to = Nan::New<Number>( cert_type);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitCertX509::Data) {
      Local<v8::Value> to;

       void *
          data =
          Nan::ObjectWrap::Unwrap<GitCertX509>(info.This())->GetValue()->data;
 // start convert_to_v8 block
  
  if (data != NULL) {
    // Wrapper data
      to = Wrapper::New((void *)data);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitCertX509::Len) {
      Local<v8::Value> to;

       size_t
         len =
         Nan::ObjectWrap::Unwrap<GitCertX509>(info.This())->GetValue()->len;
 // start convert_to_v8 block
     to = Nan::New<Number>( len);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitCertX509::constructor_template;
 