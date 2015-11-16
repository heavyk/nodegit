// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/cred_username.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/cred.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCredUsername::GitCredUsername(git_cred_username *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitCredUsername::~GitCredUsername() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCredUsername::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("CredUsername").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "parent", Parent);
         Nan::SetPrototypeMethod(tpl, "username", Username);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("CredUsername").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitCredUsername::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitCredUsername cannot be instantiated.");
     }

    GitCredUsername* object = new GitCredUsername(static_cast<git_cred_username *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitCredUsername::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitCredUsername::constructor_template), 2, argv).ToLocalChecked());
  }

  git_cred_username *GitCredUsername::GetValue() {
    return this->raw;
  }

  git_cred_username **GitCredUsername::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitCredUsername::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitCredUsername::Parent) {
      Local<v8::Value> to;

       git_cred
        *
          parent =
        &
          Nan::ObjectWrap::Unwrap<GitCredUsername>(info.This())->GetValue()->parent;
 // start convert_to_v8 block
  
  if (parent != NULL) {
    // GitCred parent
       to = GitCred::New((void *)parent, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitCredUsername::Username) {
      Local<v8::Value> to;

       char *
         username =
         Nan::ObjectWrap::Unwrap<GitCredUsername>(info.This())->GetValue()->username;
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
    Nan::Persistent<Function> GitCredUsername::constructor_template;
 