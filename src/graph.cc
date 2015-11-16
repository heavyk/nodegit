// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/graph.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/repository.h"
  #include "../include/oid.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitGraph::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "aheadBehind", AheadBehind);
         Nan::SetMethod(object, "descendantOf", DescendantOf);
  
    Nan::Set(target, Nan::New<String>("Graph").ToLocalChecked(), object);
  }

 
/*
   * @param Repository repo
   * @param Oid local
   * @param Oid upstream
    * @param Number callback
  * @param Number callback
   */
NAN_METHOD(GitGraph::AheadBehind) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid local is required.");
  }
  if (info.Length() == 2
    || (!info[2]->IsObject() && !info[2]->IsString())) {
    return Nan::ThrowError("Oid upstream is required.");
  }
  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  AheadBehindBaton* baton = new AheadBehindBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->ahead = (size_t *)malloc(sizeof(size_t ));
  baton->behind = (size_t *)malloc(sizeof(size_t ));
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_oid * from_local;
  if (info[1]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[1]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_local = oidOut;
  }
  else {
    from_local = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->local = from_local;
  baton->localNeedsFree = info[1]->IsString();
// start convert_from_v8 block
  const git_oid * from_upstream;
  if (info[2]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[2]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_upstream = oidOut;
  }
  else {
    from_upstream = Nan::ObjectWrap::Unwrap<GitOid>(info[2]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->upstream = from_upstream;
  baton->upstreamNeedsFree = info[2]->IsString();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  AheadBehindWorker *worker = new AheadBehindWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("local", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("upstream", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitGraph::AheadBehindWorker::Execute() {
  int result = git_graph_ahead_behind(
baton->ahead,baton->behind,baton->repo,baton->local,baton->upstream    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitGraph::AheadBehindWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
    Local<Object> result = Nan::New<Object>();
// start convert_to_v8 block
     to = Nan::New<Number>(* baton->ahead);
  // end convert_to_v8 block
    Nan::Set(result, Nan::New("ahead").ToLocalChecked(), to);
// start convert_to_v8 block
     to = Nan::New<Number>(* baton->behind);
  // end convert_to_v8 block
    Nan::Set(result, Nan::New("behind").ToLocalChecked(), to);
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("local"));
      workerArguments.push(GetFromPersistent("upstream"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method aheadBehind has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  if (baton->localNeedsFree) {
    baton->localNeedsFree = false;
    free((void *)baton->local);
  }
  if (baton->upstreamNeedsFree) {
    baton->upstreamNeedsFree = false;
    free((void *)baton->upstream);
  }

  delete baton;
}

   
/*
 * @param Repository repo
   * @param Oid commit
   * @param Oid ancestor
     * @return Number  result    */
NAN_METHOD(GitGraph::DescendantOf) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid commit is required.");
  }
  if (info.Length() == 2
    || (!info[2]->IsObject() && !info[2]->IsString())) {
    return Nan::ThrowError("Oid ancestor is required.");
  }
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_oid * from_commit;
  if (info[1]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[1]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_commit = oidOut;
  }
  else {
    from_commit = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const git_oid * from_ancestor;
  if (info[2]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[2]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_ancestor = oidOut;
  }
  else {
    from_ancestor = Nan::ObjectWrap::Unwrap<GitOid>(info[2]->ToObject())->GetValue();
  }
// end convert_from_v8 block
   int result = git_graph_descendant_of(
from_repo
,from_commit
,from_ancestor
  );

   if (info[1]->IsString()) {
    free((void *)from_commit);
  }
  if (info[2]->IsString()) {
    free((void *)from_ancestor);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitGraph::constructor_template;
 