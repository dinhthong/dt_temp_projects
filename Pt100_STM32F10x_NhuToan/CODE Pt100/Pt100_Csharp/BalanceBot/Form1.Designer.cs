namespace BalanceBot
{
    partial class MyForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
            base.Dispose(disposing);
            base.Dispose(disposing);
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort = new System.IO.Ports.SerialPort(this.components);
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.lblStatus = new System.Windows.Forms.Label();
            this.txt_receive = new System.Windows.Forms.TextBox();
            this.cbPort = new System.Windows.Forms.ComboBox();
            this.cbBaudrate = new System.Windows.Forms.ComboBox();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnDisconnect = new System.Windows.Forms.Button();
            this.btnConnect = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.btn_startgraph = new System.Windows.Forms.Button();
            this.btn_stopgraph = new System.Windows.Forms.Button();
            this.btn_cleargraph = new System.Windows.Forms.Button();
            this.zedGraphControl1 = new ZedGraph.ZedGraphControl();
            this.tab1 = new System.Windows.Forms.TabControl();
            this.txt_receive2 = new System.Windows.Forms.TextBox();
            this.btn_autoscroll = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.tab1.SuspendLayout();
            this.SuspendLayout();
            // 
            // serialPort
            // 
            this.serialPort.ReceivedBytesThreshold = 7;
            this.serialPort.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.AVRPort_DataReceived);
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.Transparent;
            this.tabPage1.Controls.Add(this.lblStatus);
            this.tabPage1.Controls.Add(this.txt_receive);
            this.tabPage1.Controls.Add(this.cbPort);
            this.tabPage1.Controls.Add(this.cbBaudrate);
            this.tabPage1.Controls.Add(this.btnUpdate);
            this.tabPage1.Controls.Add(this.btnDisconnect);
            this.tabPage1.Controls.Add(this.btnConnect);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(788, 381);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Setting";
            // 
            // lblStatus
            // 
            this.lblStatus.AutoSize = true;
            this.lblStatus.BackColor = System.Drawing.Color.Transparent;
            this.lblStatus.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblStatus.Location = new System.Drawing.Point(339, 131);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(2, 15);
            this.lblStatus.TabIndex = 13;
            // 
            // txt_receive
            // 
            this.txt_receive.Location = new System.Drawing.Point(339, 94);
            this.txt_receive.Name = "txt_receive";
            this.txt_receive.Size = new System.Drawing.Size(196, 20);
            this.txt_receive.TabIndex = 14;
            // 
            // cbPort
            // 
            this.cbPort.FormattingEnabled = true;
            this.cbPort.Location = new System.Drawing.Point(95, 39);
            this.cbPort.Name = "cbPort";
            this.cbPort.Size = new System.Drawing.Size(149, 21);
            this.cbPort.TabIndex = 1;
            // 
            // cbBaudrate
            // 
            this.cbBaudrate.FormattingEnabled = true;
            this.cbBaudrate.Location = new System.Drawing.Point(95, 79);
            this.cbBaudrate.Name = "cbBaudrate";
            this.cbBaudrate.Size = new System.Drawing.Size(125, 21);
            this.cbBaudrate.TabIndex = 2;
            // 
            // btnUpdate
            // 
            this.btnUpdate.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnUpdate.Location = new System.Drawing.Point(278, 34);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(98, 32);
            this.btnUpdate.TabIndex = 3;
            this.btnUpdate.Text = "Refesh COM";
            this.btnUpdate.UseVisualStyleBackColor = true;
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnDisconnect
            // 
            this.btnDisconnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnDisconnect.Location = new System.Drawing.Point(200, 123);
            this.btnDisconnect.Name = "btnDisconnect";
            this.btnDisconnect.Size = new System.Drawing.Size(86, 38);
            this.btnDisconnect.TabIndex = 12;
            this.btnDisconnect.Text = "Disconnect";
            this.btnDisconnect.UseVisualStyleBackColor = true;
            this.btnDisconnect.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnConnect
            // 
            this.btnConnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnConnect.Location = new System.Drawing.Point(86, 123);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(85, 38);
            this.btnConnect.TabIndex = 4;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.groupBox4);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(858, 398);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "View";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.label1);
            this.groupBox4.Controls.Add(this.btn_autoscroll);
            this.groupBox4.Controls.Add(this.txt_receive2);
            this.groupBox4.Controls.Add(this.btn_startgraph);
            this.groupBox4.Controls.Add(this.btn_stopgraph);
            this.groupBox4.Controls.Add(this.btn_cleargraph);
            this.groupBox4.Controls.Add(this.zedGraphControl1);
            this.groupBox4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox4.Location = new System.Drawing.Point(3, 3);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(852, 392);
            this.groupBox4.TabIndex = 14;
            this.groupBox4.TabStop = false;
            // 
            // btn_startgraph
            // 
            this.btn_startgraph.Location = new System.Drawing.Point(676, 82);
            this.btn_startgraph.Name = "btn_startgraph";
            this.btn_startgraph.Size = new System.Drawing.Size(89, 39);
            this.btn_startgraph.TabIndex = 29;
            this.btn_startgraph.Text = "Start Graph";
            this.btn_startgraph.UseVisualStyleBackColor = true;
            this.btn_startgraph.Click += new System.EventHandler(this.btn_startgraph_Click);
            // 
            // btn_stopgraph
            // 
            this.btn_stopgraph.Location = new System.Drawing.Point(676, 149);
            this.btn_stopgraph.Name = "btn_stopgraph";
            this.btn_stopgraph.Size = new System.Drawing.Size(89, 43);
            this.btn_stopgraph.TabIndex = 28;
            this.btn_stopgraph.Text = "Stop Graph";
            this.btn_stopgraph.UseVisualStyleBackColor = true;
            this.btn_stopgraph.Click += new System.EventHandler(this.btn_stopgraph_Click);
            // 
            // btn_cleargraph
            // 
            this.btn_cleargraph.Location = new System.Drawing.Point(676, 226);
            this.btn_cleargraph.Name = "btn_cleargraph";
            this.btn_cleargraph.Size = new System.Drawing.Size(89, 45);
            this.btn_cleargraph.TabIndex = 27;
            this.btn_cleargraph.Text = "CLEAR";
            this.btn_cleargraph.UseVisualStyleBackColor = true;
            this.btn_cleargraph.Click += new System.EventHandler(this.btn_cleargraph_Click);
            // 
            // zedGraphControl1
            // 
            this.zedGraphControl1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.zedGraphControl1.Location = new System.Drawing.Point(7, 20);
            this.zedGraphControl1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.zedGraphControl1.Name = "zedGraphControl1";
            this.zedGraphControl1.ScrollGrace = 0D;
            this.zedGraphControl1.ScrollMaxX = 0D;
            this.zedGraphControl1.ScrollMaxY = 0D;
            this.zedGraphControl1.ScrollMaxY2 = 0D;
            this.zedGraphControl1.ScrollMinX = 0D;
            this.zedGraphControl1.ScrollMinY = 0D;
            this.zedGraphControl1.ScrollMinY2 = 0D;
            this.zedGraphControl1.Size = new System.Drawing.Size(648, 299);
            this.zedGraphControl1.TabIndex = 1;
            this.zedGraphControl1.UseExtendedPrintDialog = true;
            this.zedGraphControl1.ZoomEvent += new ZedGraph.ZedGraphControl.ZoomEventHandler(this.zedGraphControl1_ZoomEvent);
            // 
            // tab1
            // 
            this.tab1.Controls.Add(this.tabPage2);
            this.tab1.Controls.Add(this.tabPage1);
            this.tab1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tab1.Location = new System.Drawing.Point(0, 0);
            this.tab1.Name = "tab1";
            this.tab1.SelectedIndex = 0;
            this.tab1.Size = new System.Drawing.Size(866, 424);
            this.tab1.TabIndex = 20;
            // 
            // txt_receive2
            // 
            this.txt_receive2.Location = new System.Drawing.Point(701, 343);
            this.txt_receive2.Name = "txt_receive2";
            this.txt_receive2.Size = new System.Drawing.Size(129, 20);
            this.txt_receive2.TabIndex = 30;
            // 
            // btn_autoscroll
            // 
            this.btn_autoscroll.Location = new System.Drawing.Point(676, 34);
            this.btn_autoscroll.Name = "btn_autoscroll";
            this.btn_autoscroll.Size = new System.Drawing.Size(89, 30);
            this.btn_autoscroll.TabIndex = 31;
            this.btn_autoscroll.Text = "Auto Zoom";
            this.btn_autoscroll.UseVisualStyleBackColor = true;
            this.btn_autoscroll.Click += new System.EventHandler(this.btn_autoscroll_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(710, 310);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(106, 20);
            this.label1.TabIndex = 32;
            this.label1.Text = "(time;nhietdo)";
            // 
            // MyForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(866, 424);
            this.Controls.Add(this.tab1);
            this.Name = "MyForm";
            this.Text = "Main";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MyForm_FormClosing);
            this.Load += new System.EventHandler(this.Form_Load);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.tab1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.TabControl tab1;
        private System.Windows.Forms.Label lblStatus;
        private System.Windows.Forms.TextBox txt_receive;
        private System.Windows.Forms.ComboBox cbPort;
        private System.Windows.Forms.ComboBox cbBaudrate;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnDisconnect;
        private System.Windows.Forms.Button btnConnect;
        private ZedGraph.ZedGraphControl zedGraphControl1;
        private System.Windows.Forms.Button btn_cleargraph;
        private System.Windows.Forms.Button btn_stopgraph;
        private System.Windows.Forms.Button btn_startgraph;
        private System.Windows.Forms.TextBox txt_receive2;
        private System.Windows.Forms.Button btn_autoscroll;
        private System.Windows.Forms.Label label1;
    }
}

