// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/cert.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCert::GitCert(git_cert *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitCert::~GitCert() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCert::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Cert").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "certType", CertType);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Cert").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitCert::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitCert cannot be instantiated.");
     }

    GitCert* object = new GitCert(static_cast<git_cert *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitCert::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitCert::constructor_template), 2, argv).ToLocalChecked());
  }

  git_cert *GitCert::GetValue() {
    return this->raw;
  }

  git_cert **GitCert::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitCert::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitCert::CertType) {
      Local<v8::Value> to;

       git_cert_t
         cert_type =
         Nan::ObjectWrap::Unwrap<GitCert>(info.This())->GetValue()->cert_type;
 // start convert_to_v8 block
     to = Nan::New<Number>( cert_type);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitCert::constructor_template;
 