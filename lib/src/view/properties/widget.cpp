#include <QVBoxLayout>
#include "view/properties/widget.hpp"
#include "view/properties/camera.hpp"
#include "view/properties/movement.hpp"
#include "view/properties/selection.hpp"

struct ViewPropertiesWidget::Impl {
  ViewPropertiesWidget*    self;
  ViewPropertiesSelection& selection;
  ViewPropertiesMovement&  movement;

  Impl (ViewPropertiesWidget* s) 
    : self      (s) 
    , selection (*new ViewPropertiesSelection ())
    , movement  (*new ViewPropertiesMovement ())
  {
    QVBoxLayout* layout = new QVBoxLayout;

    layout->setSpacing (0);
    layout->addWidget  (&this->selection);
    layout->setSpacing (0);
    layout->addWidget  (&this->movement);
    layout->addStretch (1);

    this->self->setLayout (layout);
  }
};

DELEGATE_BIG3_SELF (ViewPropertiesWidget)
GETTER (ViewPropertiesSelection&, ViewPropertiesWidget, selection)
GETTER (ViewPropertiesMovement& , ViewPropertiesWidget, movement)