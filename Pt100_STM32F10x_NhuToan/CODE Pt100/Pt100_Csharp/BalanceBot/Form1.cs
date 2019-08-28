using System;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using ZedGraph;
namespace BalanceBot
{

    public partial class MyForm : Form
    {
        int draw_enable=0;
        double TickStart = 0;
        int noPort = 0;
        byte[] buffer = new byte[7];
        GraphPane myPane = new GraphPane(); // Khai báo sửa dụng Graph loại GraphPane;
        PointPairList listPointsOne = new PointPairList();
        LineItem myCurveOne;
        public MyForm()
        {
            InitializeComponent();
        }
        private void Form_Load(object sender, EventArgs e)
        {
            myPane = zedGraphControl1.GraphPane;
            // set a title
            myPane.Title.Text = "Pt100";
            // set X and Y axis titles
            myPane.XAxis.Title.Text = "time";
            myPane.YAxis.Title.Text = "Nhiet do (oC)";
            myPane.YAxis.Scale.Min = -55;
            myPane.YAxis.Scale.Max = 205;
           // myPane.YAxis.Scale.
           // zedGraphControl1.IsAutoScrollRange = true;
          //  zedGraphControl1.
            zedGraphControl1.AxisChange();
            //Init Baudrate
            int[] baud_array = { 9600, 19200, 38400, 115200 };
            foreach (var item in baud_array)
            {
                cbBaudrate.Items.Add(item);
            }
            string[] port = SerialPort.GetPortNames();
            if (noPort != port.Length)
            {
                noPort = port.Length;
                cbPort.Items.Clear();
                for (int j = 0; j < noPort; j++)
                {
                    cbPort.Items.Add(port[j]);
                }
            }
            if (port.Length != 0)
                cbPort.Text = port[0];

            cbBaudrate.SelectedIndex = 2;
            lblStatus.Text = "Not Connected";
            lblStatus.ForeColor = Color.Red;
            TickStart = Environment.TickCount;
        }
        private void btnUpdate_Click(object sender, EventArgs e)
        {
            string[] port = SerialPort.GetPortNames();
            if (noPort != port.Length)
            {
                noPort = port.Length;
                cbPort.Items.Clear();
                for (int j = 0; j < noPort; j++)
                {
                    cbPort.Items.Add(port[j]);
                }
            }
        }
        private void btnConnect_Click(object sender, EventArgs e)
        {
            if (cbPort.Text == "" || cbBaudrate.Text == "null")
            {
                MessageBox.Show("Please select Port and Baudrate");
            }
            else
            {
                try
                {

                    serialPort.Close();
                    serialPort.PortName = cbPort.Text;
                    serialPort.BaudRate = int.Parse(cbBaudrate.Text);
                    serialPort.Open();
                    MessageBox.Show("Connect successfully");
                    lblStatus.Text = "Connected";
                    lblStatus.ForeColor = Color.Green;

                }
                catch (Exception ex)
                {
                    lblStatus.Text = "Not Connected";
                    lblStatus.ForeColor = Color.Red;
                    MessageBox.Show(ex.ToString());
                }
            }
        }
        Action<int> DataReceiveAction;
        private void AVRPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {

            // delegate DTA <=> DR

            DataReceiveAction = DataReceive;
            try
            {
                //goi ham DataReceive
                this.BeginInvoke(DataReceiveAction, serialPort.Read(buffer, 0, 7));
            }
            catch { };
        }
        private void DataReceive(int input)
        {
            string temp;
            double read_temp;
            bool check_temp;
            if (buffer[0] == 'a')
            {
                temp = Encoding.Default.GetString(buffer);
                temp = temp.Substring(1,temp.Length-1);
                txt_receive.Text = temp;
               // txt_receive2.Text = temp;
                check_temp = Double.TryParse(temp, out read_temp);
              if (draw_enable==1)
                draw(read_temp);
            }
            else
                serialPort.DiscardInBuffer();
        }

        public void draw(double ypoint)
        {
            zedGraphControl1.GraphPane.CurveList.Clear();
            // Time được tính bằng ms
            double time = (Environment.TickCount - TickStart) / 1000.0;
            //add point to Zed Graph
            listPointsOne.Add(time, ypoint);
            txt_receive2.Text = time.ToString("0.##") + " (s) ; " + ypoint.ToString("0.##")+" (oC)";
            myCurveOne = myPane.AddCurve(null, listPointsOne, Color.Red, SymbolType.Default);
            zedGraphControl1.AxisChange();
            zedGraphControl1.Invalidate();
        }
        private void MyForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                serialPort.Write("bbb");
                serialPort.Close();
            }
            catch (Exception)
            {

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort.Close();
                MessageBox.Show("Disconnected");
                lblStatus.Text = "Not Connected";
                lblStatus.ForeColor = Color.Red;

            }
            catch (Exception)
            {
            }
           
        }

        private void btn_cleargraph_Click(object sender, EventArgs e)
        {
            TickStart = Environment.TickCount;
            listPointsOne.Clear();
            zedGraphControl1.GraphPane.CurveList.Clear();
            zedGraphControl1.Invalidate();
            zedGraphControl1.Refresh();
        }

        private void btn_startgraph_Click(object sender, EventArgs e)
        {
            draw_enable = 1;
            listPointsOne.Clear();
            zedGraphControl1.GraphPane.CurveList.Clear();
            zedGraphControl1.Invalidate();
            zedGraphControl1.Refresh();
            TickStart = Environment.TickCount;
        }
        private void btn_stopgraph_Click(object sender, EventArgs e)
        {
            draw_enable = 0;

        }

        private void zedGraphControl1_ZoomEvent(ZedGraphControl sender, ZoomState oldState, ZoomState newState)
        {
            //Limit Y Axis range if Zoom happens
            if (myPane.YAxis.Scale.Min < -60)
                myPane.YAxis.Scale.Min = -60;
            if (myPane.YAxis.Scale.Max > 210)
                myPane.YAxis.Scale.Max = 210;
            if (myPane.XAxis.Scale.Min < 0)
                myPane.XAxis.Scale.Min = 0;
        }

        private void btn_autoscroll_Click(object sender, EventArgs e)
        {
            //  myPane.
            zedGraphControl1.ZoomOutAll(myPane);
           // zedGraphControl1.IsZoomOnMouseCenter = true;
        }
    }
}

