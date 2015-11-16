// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/cred_helpers.h>
 }

#include "../include/functions/copy.h"
#include "../include/cred_userpass_payload.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCredUserpassPayload::GitCredUserpassPayload(git_cred_userpass_payload *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitCredUserpassPayload::~GitCredUserpassPayload() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCredUserpassPayload::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("CredUserpassPayload").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "username", Username);
         Nan::SetPrototypeMethod(tpl, "password", Password);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("CredUserpassPayload").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitCredUserpassPayload::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitCredUserpassPayload cannot be instantiated.");
     }

    GitCredUserpassPayload* object = new GitCredUserpassPayload(static_cast<git_cred_userpass_payload *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitCredUserpassPayload::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitCredUserpassPayload::constructor_template), 2, argv).ToLocalChecked());
  }

  git_cred_userpass_payload *GitCredUserpassPayload::GetValue() {
    return this->raw;
  }

  git_cred_userpass_payload **GitCredUserpassPayload::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitCredUserpassPayload::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitCredUserpassPayload::Username) {
      Local<v8::Value> to;

       const char *
         username =
         Nan::ObjectWrap::Unwrap<GitCredUserpassPayload>(info.This())->GetValue()->username;
 // start convert_to_v8 block
  if (username){
       to = Nan::New<String>(username).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitCredUserpassPayload::Password) {
      Local<v8::Value> to;

       const char *
         password =
         Nan::ObjectWrap::Unwrap<GitCredUserpassPayload>(info.This())->GetValue()->password;
 // start convert_to_v8 block
  if (password){
       to = Nan::New<String>(password).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitCredUserpassPayload::constructor_template;
 