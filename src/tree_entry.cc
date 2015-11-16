// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/tree_entry.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitTreeEntry::GitTreeEntry(git_tree_entry *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitTreeEntry::~GitTreeEntry() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitTreeEntry::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("TreeEntry").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "attr", Attr);
         Nan::SetPrototypeMethod(tpl, "oid", Oid);
         Nan::SetPrototypeMethod(tpl, "filenameLen", FilenameLen);
         Nan::SetPrototypeMethod(tpl, "filename", Filename);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("TreeEntry").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitTreeEntry::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitTreeEntry cannot be instantiated.");
     }

    GitTreeEntry* object = new GitTreeEntry(static_cast<git_tree_entry *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitTreeEntry::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitTreeEntry::constructor_template), 2, argv).ToLocalChecked());
  }

  git_tree_entry *GitTreeEntry::GetValue() {
    return this->raw;
  }

  git_tree_entry **GitTreeEntry::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitTreeEntry::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitTreeEntry::Attr) {
      Local<v8::Value> to;

       uint16_t
         attr =
         Nan::ObjectWrap::Unwrap<GitTreeEntry>(info.This())->GetValue()->attr;
 // start convert_to_v8 block
     to = Nan::New<Number>( attr);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTreeEntry::Oid) {
      Local<v8::Value> to;

       git_oid
        *
          oid =
        &
          Nan::ObjectWrap::Unwrap<GitTreeEntry>(info.This())->GetValue()->oid;
 // start convert_to_v8 block
  
  if (oid != NULL) {
    // GitOid oid
       to = GitOid::New((void *)oid, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTreeEntry::FilenameLen) {
      Local<v8::Value> to;

       size_t
         filename_len =
         Nan::ObjectWrap::Unwrap<GitTreeEntry>(info.This())->GetValue()->filename_len;
 // start convert_to_v8 block
     to = Nan::New<Number>( filename_len);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTreeEntry::Filename) {
      Local<v8::Value> to;

       char *
         filename =
         Nan::ObjectWrap::Unwrap<GitTreeEntry>(info.This())->GetValue()->filename;
 // start convert_to_v8 block
  if (filename){
       to = Nan::New<String>(filename).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitTreeEntry::constructor_template;
 