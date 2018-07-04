# 数据分析：

# 目标：
* 1.红黄警相关度

相关的有7个文档：

1.AlarmDefinitions e411.xlsx

2.AlarmSample-e601 one module.xlsx

3.BL_E411Alarm_15D1-21.xlsx

4.BL_E411Alarm_64D4-25.xlsx

5.CriticalAlarms c6k_e601.xlsx

6.EventCodeID.txt

7.MappingAlgorithms.docx

* 2.设备维护

相关的有3个文档：

1.Parts Detail crosstab.csv

2.Service_Activity_Details_crosstab(2).csv

3.Active Instrument List 2018.06.08.xlsx

# 数据分析：

### 第一部分.红黄警的数据

* （1）.AlarmDefinitions e411.xlsx

* 包含特征如下：

EventCode = 事件编号 ; ModuleTypeID = 模型型号 ; ; ModuleTypeName = 模型名称 ; ComponentID = 组件编号 ; ComponentName = 组件名称 ; SubComponentID = 次组件编号 ; SubComponentName = 次组件名称 ; AlarmCode = 警报编号 ; AlarmSubCode = 次警报编号 ; AlarmType = 警报类型 ; AlarmNo = 警报编号 ; IsGeneratedByLoader = 是否由装载机导致 ; SystemClassID = 系统类型编号 ; IsMappedToMultipleSubcodes = 是否关联到多重次编号

* 总结：

该数据是”警报定义“有关的数据，针对一个警报得到的数据。

* （2）.AlarmSample -e601 one module.xlsx

* 包含特征如下：

CountryCode = 国家编号 ; SystemClassName = 仪器的种族（目前有三个）; ModuleID = 区别仪器的识别号 ;
EventCode2ID = 参照EventCode2ID这个附件内容(关联!!!!!!!!!!!!!) ; EventTimestamp = 数据发生时间点 ; XMLFileID = 可扩展标记文件序号 ; XMLFileName = 可扩展标记文件名字 ; TimeUploaded = 数据上传时间;
DimTimeID = 另一种时间序号 ; alarmCode+alarmsubCode = 报警种类编号（确定一个alarm）; AlarmSeverityDescription = 警报等级（1-9几个等级，详细资料另有附件参考）; ModuleWasUnknown = 未知模型（❌） ; AlarmCode = 报警编号 ; SubComponentName = 次级模型编号（❌）  

* 总结：

该数据是针对”某一种报警“的统计。

* （3）.BL_E411Alarm_15D1-21.xlsx

* 包含特征如下：

Id = 种类 ; DeviceID = 设备编号 ; InstrumentID = 仪器编号 ; Module ID = 模型编号 ; EventCode2ID =  (缺少) ; EventTimestamp = 发生时间点 ; XMLFileID = （缺少）可扩展标记文件序号 ;  XMLFileName = （缺少）可扩展标记文件名字 ; TimeUploaded = 上传时间点 DimTimeID = 某种时间？ （缺少） AlarmSubCode = 次警报编号 ; AlarmSeverityDescription = 警报等级（缺少）; ModuleWasUnknown = 模型未知 （❌）; AlarmCode = 警报编号 ; SubComponentName = 次级模型编号（❌）  

* 总结：

这张表是针对”某一个设备“的报警信息的统计。

这张表格告诉我设备从大到小的包含关系依次是ID -> Device ID -> Instrument ID -> Module ID -> EventCode2ID [✅] 

此外，这张表中出现的特征基本都能关联到前两张表的数据之中。


* （4）.BL_E411Alarm_64D4-25.xlsx

* 总结：
这张表格与上一张表的特征相同，

对比这两张表格，得知这两张表格分别是两个不同警报的总结。


* （5）.CriticalAlarms c6k_e601.xlsx

* ComponentID 包含特征如下：

组件名 ; 样品移液装置 ; 试剂移液装置 ; 珠粒混合机 ; 检测单元 ; 孵化器 ; 试剂盘 ; 预洗装置 ; 数码产品 ; 运输 ; T/V夹持器 ; 弹匣单元 ; 通信 ; 其他

* 总结：

【✅这张表很重要】

这张表是对关键警报E601的一个简介：

关于这个报警包含以下内容
【1】Components 如 是指每个报警由几个模块构成，例如ELECTRONICS电信号。
【2】SubComponents 是指每个模块由几个次级模块构成
【3】Relevant Alarms 有些警报和这个危险关键警报601是相关的，已经给出。
【4】Frequency 相关警报有定义一个 一天内必须发生的频次，当相关警报超出频次时，会发出最终警报。
【5】Notification Period 通知期 （一天一次还是一周一次）就是一天发送一次告诉预警局会不会发生E601这个危险红警（❌）警报。
【6】CountDay 计数的方式： 0 表示 计算发生警报的次数， 1 表示这一天内是否发生警报。

【附录给出了】
每一个ComponentID 的编号对应的实际含义, 还有每一个sub componentID 的编号对应的实际含义.

* 包含特征如下：

ModuleTypeID ; SubComponentID ; Notification ; CountDay ; Frequency ; AlarmCode ;
Alarm Type ; Alarm No ; Alarm Message ; AlarmDesc ; AlarmRemedy = 警报诊断 ; Alarm Severity = 警报严重程度 ; Critical Level = 严重等级

* （6）.EventCodeID.txt


* 包含特征如下：

EventCode2ID = 事件code与ID的相关性 ; ModuleTypeID ; ModuleTypeName ; SystemClassID ; SystemClassName ; ComponentID ; ComponentName ; SubComponentID ; SubComponentName ; AlarmCode ; AlarmSubCode ; AlarmType ; AlarmNo ; IsGeneratedByLoader ; IsMappedToMultipleSubcodes ; AlarmSeverityID; AlarmSeverityName ; Message = 报警信息 ;  Description = 描述 ; Remedy 诊断 ; CriticalLevel ; Frequency ; Notification Period 


* 总结：

这张表是跟警报有关的信息

【✅】是根据这张表将不同警报的信息转成一个顺序编号的ID.【？？？这种表记录了各种报警的总信息】



* （7）.MappingAlgorithms.docx

* 包含特征如下
Mapping particularities = 映射特殊性 ; System class = 系统 ; Scheme Name = 方案名 ;
ModuleType 模型类型 ; Mapping algorithm = 映射算法

* 总结：

这张表是总结了警报alarm到模型种类module id的一个映射：两种方法 

CDB之中，我们接受了警报的种类和警报的NO.

RIGM之中，我们有两种情况:

1.AlarmCode 和 SubAlarmCode是0 那么alarm是由AlarmCode唯一决定的。

2.或者当SubAlarmCode 不是0 的时候，alarm由两者共同决定。

如果这个报警由 子组件名、AlarmCode和AlarmSubCode共同决定，那么映射的步骤是如何如何的。

[❌]
这张表很重要，但是我并不是很理解为什么需要将Alarm映射到一个Module e601?

### 第二部分.设备维护的数据：
* （1）.Parts Detail crosstab.csv

* 包含特征如下：
CaseCustomerNumber: 用户情况编号 ; 客户 ; CaseCustomerPrimaryState =用户来自哪里 ; 
ServiceActivityNumber = 机器提供服务编号 ; SAStatus = 最终状态 ; SACodeGroup = 使用设备统计 ; SACodeDescription = 描述 ; EffectiveActivityDate = 活跃时间 ; InstrumentFamilyName = 机器家族名（三选一）; Instrument Line = 仪表线 ; InstrumentMaterialNo = 材料号 ; Serial No = 序列号 ; InstrumentName =设备名 ; User ID = 用户号 ; Employee Name = 雇员名 ;Supervisor_Name = 监督人名 ; AM_Name = ？ ; RM_Name = ？; Spare Part Number = 备件号 ; Spare Part Number = 备件名 ; ListPrice = 价格 ; InvoiceNotes = 故障笔记 ; StockNumber = ? ; MaterialStatusTextEn = 材料状态 ; 零配件数量 ; 零配件金额(List Price 数量) 

* 总结：
这张表给出的信息很细碎，然后最重要的一列是故障笔记。InvoiceNotes. 推测整张表是故障发生时采集到的各种数据。

* （2）.Service_Activity_Details_crosstab(2).csv

* 包含特征如下：

ServiceActivityNumber ; CaseNumberSFDC ; InstrumentName ; BA ? ;InstrumentFamilyName ?
InstrumentLineName ; InstrumentSerialNo ; CaseCustomerNumber ; 客户 ; CaseCustomerPrimaryState 客户地点 ; SACodeDescription 产生信息的方式 ; Service Activity Group 服务的种类 ; SACreateDate 日期时间 ; EffectiveActivityDate 有效活动日期 ;ServiceActivityLastLabourEndDate  服务活动最后终止时间 ; ServiceActivityLastLabourDocumentationDate 服务活动最后记录时间 ; 
CompletionDate 完成时间 ; 
CaseDueDate (缺少) ; 
SAStatus 状态 ; 
InvoiceNotes =记录信息 ;
工时Working = 维修时长 ; 
工时Travel = 旅游工时 ;
服务工时 ; 零配件数


* 总结：
这张表和第一张表的信息大部分重合，这张表补充的有维修所用的一些时间还有机器记录的最后时间。

* （3）.Active Instrument List 2018.06.08.xlsx 

* 未能拿到（❌）


# 问题回答：
* 1、红黄警分析：

* 问：c6k/c8k的红黄警数据；code代号与红黄警名称的mapping关系；选择哪两个红警code进行后续的分析。 E411的code代号与红黄警名称的mapping关系；选择哪一个红警code进行后续分析。


* 答：在表格7 MappingAlgorithms.docx 中可以看到e601与e411module的映射采用rigm方法。
我觉得可以采取e601 和 e411作为重点红警进行分析。因为表3.BL_E411Alarm_15D1-21.xlsx 4.BL_E411Alarm_64D4-25.xlsx正好以这两个红警为例进行了分析。在表格5.CriticalAlarms c6k_e601.xlsx中看到e601是一种危险的红警。

但我没有区别开哪些是属于黄色警报。[?]


* 2、设备预测性维护，关于c6k/c8k一个模块的以下六大类数据

* 问： 是否满足六大类别？

* 答： 我觉得第五类比较少。
第一类：错误时间，错误机器型号 ，错误种类 ✅ 满足

第二类：维修历史，InvoiceNotes 设备，维护的行为，维修的时间 ✅ 满足

第三类：机器情况，后两个表格中给出了用户操作机器的一些信息，包括用户如何操作，包括用户的地理位置 ✅ 满足

第四类：机器特征，最后一个表格中给出了机器的名称，机器的地点。机器的种类，机器的序列号。 ✅满足

第五类：运行情况，环境变量，交互信息，只有机器的名字，有点缺少比如机器的表现，大部分是机器出错的信息❌

第六类：操作者信息，最后一张表给出了操作者的名字和时长 ✅ 满足


# 总结：
按照之前表格的顺序，

表1是对某一类型的警报的统计，仅涉及警报自身
表2是某一种警报的样例，涉及警报和警报机器情况，完整，适合用作模型训练
表3，4 是关联了Module id 和 某一类alarm信息.
表5是对一种特殊红警e601的简介，介绍了一个警报含有的相关信息的含义
表6跟event 转换成 id 有关
表7是mapping的2种方式介绍，介绍如何从alarm转到module.

表8表9是测试维护的时候需要用到的六类机器故障特征

# 希望：
希望客户能够解释一下mapping的意义。
希望客户能补充六类数据中的第五类数据。

