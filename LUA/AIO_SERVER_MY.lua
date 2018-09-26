local AIO=AIO or require("AIO")

if AIO.AddAddon() then 
   return
end

local MyHandlers = AIO.AddHandlers("GET_ITEM_DIALOG",{})
local ItemEtry_C=-1
local ItemsInfo_C={}
-- local Dialog_Conf_Tab={--show参数参考
--    content="|cffff00005积分|r",--显示的文字
--    texture="Interface\\Icons\\INV_Chest_Cloth_23",--图标
--    name="|cffff0000学者长袍|r",--图标后的文字
--    color={0.61, 0.61, 0.61, 1},--rgb
--    link=1,--个数后面的物品链接
--    index=1,
--    count=1,--图标上显示的个数
-- }

 MerchantFrame:HookScript("OnHide", function ( ... )--钩子函数到相应的事件
   StaticPopup_Hide("GET_ITEM_BY_MY_MONEY")
end)
-- hooksecurefunc("MerchantFrame_OnHide",hides_my)--钩子函数到相应函数

StaticPopupDialogs["CONFIRM_PURCHASE_TOKEN_ITEM"] = {--覆盖原生，添加show后隐藏自定义
   text = CONFIRM_PURCHASE_TOKEN_ITEM, 
   button1 = YES,
   button2 = NO,
   OnAccept = function()
      BuyMerchantItem(MerchantFrame.itemIndex, MerchantFrame.count);
   end,
   OnCancel = function()
      
   end,
   OnShow = function()
      StaticPopup_Hide("GET_ITEM_BY_MY_MONEY")
   end,
   OnHide = function()
      
   end,
   timeout = 0,
   hideOnEscape = 1,
   hasItemFrame = 1,--控制是否有物品按钮
}
StaticPopupDialogs["GET_ITEM_BY_MY_MONEY"] = {
   text = "该物品需要以下物品进行兑换: %s ", --这个不可以改动，默认的样式
   button1 = "兑换",
   button2 = "取消",
   OnAccept = function()
      if ( ItemEtry_C >= -1) then
         AIO.Handle("GET_ITEM_DIALOG","GiveItem",ItemEtry_C)--调用服务端给予物品函数
      else
         AIO.Handle("GET_ITEM_DIALOG","SendMessage")--调用服务端错误信息提示函数
      end

   end,
   OnCancel = function()
      
   end,
   OnShow = function()
      StaticPopup_Hide("CONFIRM_PURCHASE_TOKEN_ITEM")--自定义的开启后隐藏原生
   end,
   OnHide = function()
      
   end,
   timeout = 0,
   hideOnEscape = 1,
}
function ShowFrame( player )
   StaticPopup_Show("GET_ITEM_BY_MY_MONEY", GetExitem(ItemEtry_C))--, {["texture"] = itemTexture , ["name"] = sName,["color"] = {0.61, 0.61, 0.61, 1}, ["link"] = sLink, ["index"] = 1, ["count"] = 1});
end
function MyHandlers.GetTabStat_C(player,tab_key_len)--判断客户端数据长度和服务端是否相同
   local len= GetTabLen(ItemsInfo_C)
   if( (tab_key_len ~= len or len==0 ) and tab_key_len~=0) then
         AIO.Handle("GET_ITEM_DIALOG","WirteTabItems_S")
   end
end
function MyHandlers.WirteTabItems_C(player,ItemsInfo_Tab_S)--写入服务端数据
   ItemsInfo_C=ItemsInfo_Tab_S
end

function MyHandlers.ShowDialog_Client(player,ItemEtry_S)
   for k in pairs(ItemsInfo_C) do
      if ( ItemEtry_S == k ) then
         ItemEtry_C=ItemEtry_S
         ShowFrame(player)
         break
      end  
   end
end
function GetExitem(entry)
   local str="|n|n"
   for k,v in pairs(ItemsInfo_C[entry]) do
      if(string.len(k)==8 and v > 0)then
         str=str.."|cffff0000"..(tostring(ItemsInfo_C[entry][k.."_count"])..ItemsInfo_C[entry][k.."_link"]).."|r|n"
      end
   end
   return str
end
function GetTabLen(tab)
   local len=0
   for k in pairs(tab) do
      if(k)then
         len=len+1
      end
   end
   return len
end

