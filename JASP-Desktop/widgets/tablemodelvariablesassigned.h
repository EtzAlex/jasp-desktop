#ifndef TABLEMODELVARIABLESASSIGNED_H
#define TABLEMODELVARIABLESASSIGNED_H

#include <QAbstractListModel>

#include "options/optionfieldpairs.h"
#include "listmodelvariables.h"
#include "tablemodel.h"
#include "droptarget.h"

typedef QList<ColumnInfo> VarPair;

class TableModelVariablesAssigned : public TableModel, public BoundModel, public DropTarget
{
	Q_OBJECT
public:
	explicit TableModelVariablesAssigned(QObject *parent = 0);
	
	void setVariableTypesAllowed(int variableTypesAllowed);
	int variableTypesAllowed();

	void bindTo(Option *option) override;
	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent) const override;
	QVariant data(const QModelIndex &index, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;

	virtual Qt::DropActions supportedDropActions() const override;
	virtual Qt::DropActions supportedDragActions() const override;
	virtual QStringList mimeTypes() const override;
	virtual QMimeData *mimeData(const QModelIndexList &indexes) const override;
	virtual bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) override;
	virtual bool canDropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) const override;

	bool isForbidden(int variableType) const;

	virtual bool insertRows(int row, int count, const QModelIndex &parent) override;
	virtual bool removeRows(int row, int count, const QModelIndex &parent) override;

protected:
	void assignToOption();

private:
	int _variableTypesAllowed;

	OptionFieldPairs *_boundTo;
	QList<VarPair> _values;

	void pairsChanged();

	static std::vector<std::pair<std::string, std::string> > asVector(QList<VarPair> values);
	
};

#endif // TABLEMODELVARIABLESASSIGNED_H