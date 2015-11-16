#ifndef GITCVARMAP_H
#define GITCVARMAP_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitCvarMap : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_cvar_map *GetValue();
    git_cvar_map **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitCvarMap(git_cvar_map *raw, bool selfFreeing);
    ~GitCvarMap();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(CvarType);
    static NAN_METHOD(StrMatch);
    static NAN_METHOD(MapValue);
    git_cvar_map *raw;
};

#endif
