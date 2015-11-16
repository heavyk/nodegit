// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/cert_hostkey.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCertHostkey::GitCertHostkey(git_cert_hostkey *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitCertHostkey::~GitCertHostkey() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCertHostkey::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("CertHostkey").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "certType", CertType);
         Nan::SetPrototypeMethod(tpl, "type", Type);
         Nan::SetPrototypeMethod(tpl, "hashMd5", HashMd5);
         Nan::SetPrototypeMethod(tpl, "hashSha1", HashSha1);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("CertHostkey").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitCertHostkey::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitCertHostkey cannot be instantiated.");
     }

    GitCertHostkey* object = new GitCertHostkey(static_cast<git_cert_hostkey *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitCertHostkey::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitCertHostkey::constructor_template), 2, argv).ToLocalChecked());
  }

  git_cert_hostkey *GitCertHostkey::GetValue() {
    return this->raw;
  }

  git_cert_hostkey **GitCertHostkey::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitCertHostkey::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitCertHostkey::CertType) {
      Local<v8::Value> to;

       git_cert_t
         cert_type =
         Nan::ObjectWrap::Unwrap<GitCertHostkey>(info.This())->GetValue()->cert_type;
 // start convert_to_v8 block
     to = Nan::New<Number>( cert_type);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitCertHostkey::Type) {
      Local<v8::Value> to;

       git_cert_ssh_t
         type =
         Nan::ObjectWrap::Unwrap<GitCertHostkey>(info.This())->GetValue()->type;
 // start convert_to_v8 block
     to = Nan::New<Number>( type);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitCertHostkey::HashMd5) {
      Local<v8::Value> to;

      char* hash_md5 = (char *)Nan::ObjectWrap::Unwrap<GitCertHostkey>(info.This())->GetValue()->hash_md5;
 // start convert_to_v8 block
  if (hash_md5){
      to = Nan::New<String>(hash_md5, 16).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitCertHostkey::HashSha1) {
      Local<v8::Value> to;

      char* hash_sha1 = (char *)Nan::ObjectWrap::Unwrap<GitCertHostkey>(info.This())->GetValue()->hash_sha1;
 // start convert_to_v8 block
  if (hash_sha1){
      to = Nan::New<String>(hash_sha1, 20).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitCertHostkey::constructor_template;
 