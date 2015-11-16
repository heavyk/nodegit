// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/transfer_progress.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitTransferProgress::GitTransferProgress(git_transfer_progress *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitTransferProgress::~GitTransferProgress() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitTransferProgress::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("TransferProgress").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "totalObjects", TotalObjects);
         Nan::SetPrototypeMethod(tpl, "indexedObjects", IndexedObjects);
         Nan::SetPrototypeMethod(tpl, "receivedObjects", ReceivedObjects);
         Nan::SetPrototypeMethod(tpl, "localObjects", LocalObjects);
         Nan::SetPrototypeMethod(tpl, "totalDeltas", TotalDeltas);
         Nan::SetPrototypeMethod(tpl, "indexedDeltas", IndexedDeltas);
         Nan::SetPrototypeMethod(tpl, "receivedBytes", ReceivedBytes);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("TransferProgress").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitTransferProgress::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitTransferProgress cannot be instantiated.");
     }

    GitTransferProgress* object = new GitTransferProgress(static_cast<git_transfer_progress *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitTransferProgress::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitTransferProgress::constructor_template), 2, argv).ToLocalChecked());
  }

  git_transfer_progress *GitTransferProgress::GetValue() {
    return this->raw;
  }

  git_transfer_progress **GitTransferProgress::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitTransferProgress::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitTransferProgress::TotalObjects) {
      Local<v8::Value> to;

       unsigned int
         total_objects =
         Nan::ObjectWrap::Unwrap<GitTransferProgress>(info.This())->GetValue()->total_objects;
 // start convert_to_v8 block
     to = Nan::New<Number>( total_objects);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTransferProgress::IndexedObjects) {
      Local<v8::Value> to;

       unsigned int
         indexed_objects =
         Nan::ObjectWrap::Unwrap<GitTransferProgress>(info.This())->GetValue()->indexed_objects;
 // start convert_to_v8 block
     to = Nan::New<Number>( indexed_objects);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTransferProgress::ReceivedObjects) {
      Local<v8::Value> to;

       unsigned int
         received_objects =
         Nan::ObjectWrap::Unwrap<GitTransferProgress>(info.This())->GetValue()->received_objects;
 // start convert_to_v8 block
     to = Nan::New<Number>( received_objects);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTransferProgress::LocalObjects) {
      Local<v8::Value> to;

       unsigned int
         local_objects =
         Nan::ObjectWrap::Unwrap<GitTransferProgress>(info.This())->GetValue()->local_objects;
 // start convert_to_v8 block
     to = Nan::New<Number>( local_objects);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTransferProgress::TotalDeltas) {
      Local<v8::Value> to;

       unsigned int
         total_deltas =
         Nan::ObjectWrap::Unwrap<GitTransferProgress>(info.This())->GetValue()->total_deltas;
 // start convert_to_v8 block
     to = Nan::New<Number>( total_deltas);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTransferProgress::IndexedDeltas) {
      Local<v8::Value> to;

       unsigned int
         indexed_deltas =
         Nan::ObjectWrap::Unwrap<GitTransferProgress>(info.This())->GetValue()->indexed_deltas;
 // start convert_to_v8 block
     to = Nan::New<Number>( indexed_deltas);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTransferProgress::ReceivedBytes) {
      Local<v8::Value> to;

       size_t
         received_bytes =
         Nan::ObjectWrap::Unwrap<GitTransferProgress>(info.This())->GetValue()->received_bytes;
 // start convert_to_v8 block
     to = Nan::New<Number>( received_bytes);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitTransferProgress::constructor_template;
 