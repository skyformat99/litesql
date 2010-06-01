#ifndef __LitesqlRelationPanel__
#define __LitesqlRelationPanel__

/**
@file
Subclass of RelationPanel, which is generated by wxFormBuilder.
*/

#include "ui.h"
#include "ddx.h"

namespace xml 
{
  class Relation;
}

/** Implementing RelationPanel */
class LitesqlRelationPanel : public ui::RelationPanel, TransferableData
{
public:
  /** Constructor */
  LitesqlRelationPanel( wxWindow* parent , xml::Relation* pRelation);

  bool TransferDataToWindow()  { return TransferData(true); }

  bool TransferDataFromWindow()  { return TransferData(false); }

protected:
  bool TransferData(bool toWindow);

private:
  xml::Relation* m_pRelation;
};

#endif // __LitesqlRelationPanel__