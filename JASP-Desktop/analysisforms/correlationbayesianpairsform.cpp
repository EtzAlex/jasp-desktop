#include "correlationbayesianpairsform.h"
#include "ui_correlationbayesianpairsform.h"

#include "widgets/tablemodelvariablesassigned.h"

CorrelationBayesianPairsForm::CorrelationBayesianPairsForm(QWidget *parent) :
	AnalysisForm("CorrelationBayesianPairsForm", parent),
	ui(new Ui::CorrelationBayesianPairsForm)
{
	ui->setupUi(this);

	_availableVariablesModel.setSupportedDropActions(Qt::MoveAction);
	_availableVariablesModel.setSupportedDragActions(Qt::CopyAction);
	_availableVariablesModel.setVariableTypesSuggested(Column::ColumnTypeScale);
	_availableVariablesModel.setVariableTypesAllowed(Column::ColumnTypeScale | Column::ColumnTypeOrdinal | Column::ColumnTypeNominal);

	ui->availableFields->setModel(&_availableVariablesModel);
	ui->availableFields->setDefaultDropAction(Qt::MoveAction);
	ui->availableFields->setDoubleClickTarget(ui->pairs);

	TableModelPairsAssigned *model = new TableModelPairsAssigned(this);
	model->setSource(&_availableVariablesModel);
	model->setVariableTypesSuggested(Column::ColumnTypeScale);
	model->setVariableTypesAllowed(Column::ColumnTypeScale | Column::ColumnTypeOrdinal | Column::ColumnTypeNominal);
	ui->pairs->setModel(model);

	ui->assignButton->setSourceAndTarget(ui->availableFields, ui->pairs);

#ifdef QT_NO_DEBUG
	ui->plotBayesFactorRobustness->hide();
	ui->plotSequentialAnalysis->hide();
	ui->plotSequentialAnalysisRobustness->hide();
	ui->groupPrior->hide();
#else
	ui->plotBayesFactorRobustness->setStyleSheet("background-color: pink;");
	ui->plotSequentialAnalysis->setStyleSheet("background-color: pink;");
	ui->plotSequentialAnalysisRobustness->setStyleSheet("background-color: pink;");
	ui->groupPrior->setStyleSheet("background-color: pink;");
#endif
}

CorrelationBayesianPairsForm::~CorrelationBayesianPairsForm()
{
	delete ui;
}
