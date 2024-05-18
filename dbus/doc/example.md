参数参考：
https://www.cnblogs.com/alexyuyu/articles/5070229.html


root@gnr5713bb:~# busctl  introspect  xyz.openbmc_project.State.Chassis /xyz/openbmc_project/state/chassis0
NAME                                   TYPE      SIGNATURE  RESULT/VALUE                             FLAGS
org.freedesktop.DBus.Introspectable    interface -          -                                        -
.Introspect                            method    -          s                                        -
org.freedesktop.DBus.ObjectManager     interface -          -                                        -
.GetManagedObjects                     method    -          a{oa{sa{sv}}}                            -
.InterfacesAdded                       signal    oa{sa{sv}} -                                        -
.InterfacesRemoved                     signal    oas        -                                        -
org.freedesktop.DBus.Peer              interface -          -                                        -
.GetMachineId                          method    -          s                                        -
.Ping                                  method    -          -                                        -
org.freedesktop.DBus.Properties        interface -          -                                        -
.Get                                   method    ss         v                                        -
.GetAll                                method    s          a{sv}                                    -
.Set                                   method    ssv        -                                        -
.PropertiesChanged                     signal    sa{sv}as   -                                        -
xyz.openbmc_project.State.Chassis      interface -          -                                        -
.CurrentPowerState                     property  s          "xyz.openbmc_project.State.Chassis.Po... emits-change writable
.CurrentPowerStatus                    property  s          "xyz.openbmc_project.State.Chassis.Po... emits-change writable
.LastStateChangeTime                   property  t          0                                        emits-change writable
.RequestedPowerTransition              property  s          "xyz.openbmc_project.State.Chassis.Tr... emits-change writable
xyz.openbmc_project.State.PowerOnHours interface -          -                                        -
.POHCounter                            property  u          0                                        emits-change writable
root@gnr5713bb:~# 
root@gnr5713bb:~# 
root@gnr5713bb:~# 
root@gnr5713bb:~# busctl  introspect  xyz.openbmc_project.State.Chassis /xyz/openbmc_project/state/chassis0 xyz.openbmc_project.State.Chassis
NAME                              TYPE      SIGNATURE RESULT/VALUE                             FLAGS
.CurrentPowerState                property  s         "xyz.openbmc_project.State.Chassis.Po... emits-change writable
.CurrentPowerStatus               property  s         "xyz.openbmc_project.State.Chassis.Po... emits-change writable
.LastStateChangeTime              property  t         0                                        emits-change writable
.RequestedPowerTransition         property  s         "xyz.openbmc_project.State.Chassis.Tr... emits-change writable
root@gnr5713bb:~# busctl  introspect  xyz.openbmc_project.State.Chassis /xyz/openbmc_project/state/chassis0 xyz.openbmc_project.State.Chassis CurrentPowerStatus
Too many arguments.
root@gnr5713bb:~# busctl  get-property  xyz.openbmc_project.State.Chassis /xyz/openbmc_project/state/chassis0 xyz.openbmc_project.State.Chassis CurrentPowerStatus
s "xyz.openbmc_project.State.Chassis.PowerStatus.Good"
root@gnr5713bb:~# busctl  get-property  xyz.openbmc_project.State.Chassis /xyz/openbmc_project/state/chassis0 xyz.openbmc_project.State.Chassis CurrentPowerState 
s "xyz.openbmc_project.State.Chassis.PowerState.Off"
root@gnr5713bb:~# 


## 读power状态：
busctl  get-property  xyz.openbmc_project.State.Chassis1 /xyz/openbmc_project/state/chassis1 xyz.openbmc_project.State.Chassis CurrentPowerState

## 设置power状态：
busctl  set-property  xyz.openbmc_project.State.Chassis /xyz/openbmc_project/state/chassis0 xyz.openbmc_project.State.Chassis CurrentPowerState s xyz.openbmc_project.State.Chassis.PowerState.Off
busctl get-property xyz.openbmc_project.State.Chassis /xyz/openbmc_project/state/chassis0 xyz.openbmc_project.State.Chassis CurrentPowerState


## 设置OS running：
busctl set-property xyz.openbmc_project.State.Host /xyz/openbmc_project/state/host0 xyz.openbmc_project.State.Host CurrentHostState s xyz.openbmc_project.State.Host.HostState.Running
busctl get-property xyz.openbmc_project.State.Host /xyz/openbmc_project/state/host0 xyz.openbmc_project.State.Host CurrentHostState


## call 样例：
busctl call xyz.openbmc_project.ObjectMapper /xyz/openbmc_project/object_mapper xyz.openbmc_project.ObjectMapper GetSubTree sias /xyz/openbmc_project/inventory 0 0 --verbose

busctl call xyz.openbmc_project.ObjectMapper /xyz/openbmc_project/object_mapper xyz.openbmc_project.ObjectMapper GetSubTree sias /xyz/openbmc_project/sensors 2 0 --verbose


busctl call xyz.openbmc_project.EntityManager / org.freedesktop.DBus.ObjectManager GetManagedObjects --verbose
# 获取bus：11 address：80 的fru：
busctl call xyz.openbmc_project.FruDevice /xyz/openbmc_project/FruDevice xyz.openbmc_project.FruDeviceManager GetRawFru yy 11 80
busctl call xyz.openbmc_project.Ipmi.Channel.Ipmb /xyz/openbmc_project/Ipmi/Channel/Ipmb org.openbmc.Ipmb sendRequest yyyyay 4 0x3a 0 0x04 5 5 0x20 0x01 0x00 0x05
busctl call xyz.openbmc_project.ObjectMapper /xyz/openbmc_project/object_mapper xyz.openbmc_project.ObjectMapper GetSubTree sias /xyz/openbmc_project/inventory 0 0

# BMC 内使用ipmitool raw 6 1 内部是调用dbus接口：
busctl  call  xyz.openbmc_project.Ipmi.Host /xyz/openbmc_project/Ipmi xyz.openbmc_project.Ipmi.Server execute yyyaya{sv} 6 1 1 0 0

busctl call xyz.openbmc_project.Ipmi.Channel.Ipmb /xyz/openbmc_project/Ipmi/Channel/Ipmb org.openbmc.Ipmb sendRequest yyyyay 4 0 0 0x2 1 0x1 >> /home/root/power_cycle.log
==
    constexpr auto IPMB_NAME = "xyz.openbmc_project.Ipmi.Channel.Ipmb";
    constexpr auto IPMB_OBJ = "/xyz/openbmc_project/Ipmi/Channel/Ipmb";
    constexpr auto IPMB_INTF = "org.openbmc.Ipmb";
    uint8_t bic_node_channel = g_channel*4;
    uint8_t netfn=0;
    uint8_t lun=0;
    uint8_t cmd=2;
    std::vector<uint8_t> Data;
    auto ipmb = bus->new_method_call(IPMB_NAME, IPMB_OBJ,IPMB_INTF, "sendRequest");
    Data = {0x01};
    ipmb.append(bic_node_channel, netfn, lun, cmd, Data);
    auto reply = bus->call(ipmb);
    if (reply.is_method_error())
    {
        return ipmi::responseUnspecifiedError();
    }

## ipmi 和ME交互
# (raw 6 2)
busctl call xyz.openbmc_project.Ipmi.Channel.Ipmb /xyz/openbmc_project/Ipmi/Channel/Ipmb org.openbmc.Ipmb sendRequest yyyyay 1 6 0 0x2 0
# (raw 6 1)
busctl call xyz.openbmc_project.Ipmi.Channel.Ipmb /xyz/openbmc_project/Ipmi/Channel/Ipmb org.openbmc.Ipmb sendRequest yyyyay 1 6 0 0x1 0
# (raw 4 0x2d ....)
busctl call xyz.openbmc_project.Ipmi.Channel.Ipmb /xyz/openbmc_project/Ipmi/Channel/Ipmb org.openbmc.Ipmb sendRequest yyyyay 1 4 0 0x2d 1 0x08
# (lock ME region (ME recovery))
busctl call xyz.openbmc_project.Ipmi.Channel.Ipmb /xyz/openbmc_project/Ipmi/Channel/Ipmb org.openbmc.Ipmb sendRequest yyyyay 1 0x2e 0 0xe7 4 0x57 0x01 0x0 0x0
# (unlock ME region (exit ME recovery))
busctl call xyz.openbmc_project.Ipmi.Channel.Ipmb /xyz/openbmc_project/Ipmi/Channel/Ipmb org.openbmc.Ipmb sendRequest yyyyay 1 0x2e 0 0xe7 4 0x57 0x01 0x0 0x1



busctl call xyz.openbmc_project.Time.Manager /xyz/openbmc_project/time/bmc org.freedesktop.DBus.Properties Set ssv xyz.openbmc_project.Time.EpochTime Elapsed t 0
busctl call xyz.openbmc_project.Time.Manager /xyz/openbmc_project/time/bmc org.freedesktop.DBus.Properties Get ss xyz.openbmc_project.Time.EpochTime Elapsed    
v t 1676016312354360

busctl  set-property xyz.openbmc_project.HealthMon /xyz/openbmc_project/sensors/utilization/CPU   xyz.openbmc_project.Association.Definitions Associations "a(sss)" 1 chassis all_sensors /xyz/openbmc_project/inventory/system/board/sr6115


busctl call xyz.openbmc_project.ObjectMapper /xyz/openbmc_project/object_mapper xyz.openbmc_project.ObjectMapper GetSubTreePaths sias /xyz/openbmc_project/inventory/system 2 1 xyz.openbmc_project.Inventory.Item.Board

##监控P1V8_BMC_AUX sensor
busctl monitor --system --match "type='signal',interface='org.freedesktop.DBus.Properties',member='PropertiesChanged',path='/xyz/openbmc_project/sensors/voltage/P1V8_BMC_AUX',arg0='xyz.openbmc_project.Sensor.Value'"

busctl monitor --system --match "type='signal',interface='org.freedesktop.DBus.Properties',member='PropertiesChanged',path='/xyz/openbmc_project/sensors/voltage/P1V8_BMC_AUX',arg0namespace='xyz.openbmc_project.Sensor.Value'"

busctl monitor --system --match "type='signal',interface='org.freedesktop.DBus.Properties',member='PropertiesChanged',path='/xyz/openbmc_project/sensors/voltage/P1V8_BMC_AUX'"

busctl monitor --system --match "type='signal',interface='org.freedesktop.DBus.Properties',member='PropertiesChanged',path='/xyz/openbmc_project/inventory/system/chassis/motherboard',arg0namespace='xyz.openbmc_project.Configuration.ADC'"