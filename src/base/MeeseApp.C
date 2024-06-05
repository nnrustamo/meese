#include "MeeseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MeeseApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

MeeseApp::MeeseApp(InputParameters parameters) : MooseApp(parameters)
{
  MeeseApp::registerAll(_factory, _action_factory, _syntax);
}

MeeseApp::~MeeseApp() {}

void
MeeseApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<MeeseApp>(f, af, s);
  Registry::registerObjectsTo(f, {"MeeseApp"});
  Registry::registerActionsTo(af, {"MeeseApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MeeseApp::registerApps()
{
  registerApp(MeeseApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MeeseApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MeeseApp::registerAll(f, af, s);
}
extern "C" void
MeeseApp__registerApps()
{
  MeeseApp::registerApps();
}
